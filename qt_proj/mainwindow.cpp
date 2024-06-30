#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Schedule.h"
#include "add_schedule.h"
#include "delete_schedule.h"
#include "modify_schedule.h"
#include <QtWidgets>
#include <QtUiTools/QUiLoader>
#include <QFile>
#include <QDate>
#include <QPixmap>
bool (*compareFunc)(const Schedule&, const Schedule&) = Schedule::Compare1;




MainWindow::MainWindow(std::list<Schedule> & schedulelist, QWidget *parent, QDate currentDate_)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , schedulelist(schedulelist)
    , currentDate(currentDate_)
    , tempdate(currentDate_)
    , image("D:\\code\\csh\\qt\\QT-project\\background.jpg")
{
    ui->setupUi(this);
    ui ->Sort_with_Time->hide();
    addScheduleWindow = new Add_Schedule(schedulelist,this);
    deleteScheduleWindow = new Delete_Schedule(schedulelist,this);
    modifyScheduleWindow = new Modify_Schedule(schedulelist,this);

    calendar = ui->calendarWidget;
    calendar->setSelectedDate(tempdate);
    connect(calendar, &QCalendarWidget::selectionChanged, this, &MainWindow::onCalendarSelectionChanged);


    ShowSchedule(tempdate);

    modify_layout = ui->verticalLayout_2;

    background = ui->label;
    background->setPixmap(QPixmap::fromImage(image));
    background->setScaledContents(true);
    ui->verticalLayout_2->addWidget(background,0,Qt::AlignCenter);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer->start(1000);
    timerlabel = ui->label_2;
    timerlabel->setAlignment(Qt::AlignCenter);
    timerlabel->setStyleSheet("font-size: 24pt;");
    ui->verticalLayout_2->addWidget(timerlabel,0,Qt::AlignCenter); // 将 QLabel 添加到布局中
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Sort_with_Time_clicked(){
    compareFunc =Schedule::Compare1;
    ui->Sort_with_Time->hide();
    ui->Sort_with_Rating->show();
    ShowSchedule(tempdate);
}

void MainWindow::on_Sort_with_Rating_clicked(){
    compareFunc =Schedule::Compare2;
    ui->Sort_with_Rating->hide();
    ui->Sort_with_Time->show();
    ShowSchedule(tempdate);
}

void MainWindow::on_Add_Schedule_clicked()
{
    qDebug() << "Add Schedule opened\n";
    qDebug() << schedulelist.size();
    addScheduleWindow->show();
    connect(addScheduleWindow, &Add_Schedule::scheduleClosed, this, &MainWindow::handleScheduleClosed);
}


void MainWindow::on_Delete_Schedule_clicked(Schedule sd)
{
    qDebug() << "Delete Schedule opened\n";
    qDebug() << schedulelist.size();
    deleteScheduleWindow->s = sd;
    deleteScheduleWindow->show();
    connect(deleteScheduleWindow, &Delete_Schedule::scheduleClosed, this, &MainWindow::del_handleScheduleClosed);
}
void MainWindow::on_Modify_Schedule_clicked(Schedule sd){
    ui->label->hide();
    ui->label_2->hide();
    modify_layout->addWidget(modifyScheduleWindow);

    qDebug() << "Modify Schedule opened\n";
    qDebug() << schedulelist.size();
    modifyScheduleWindow->s = sd;
    modifyScheduleWindow->lineEdit->setText(sd.GetTaskName());
    modifyScheduleWindow->NoteEdit->setText(sd.GetContent());
    modifyScheduleWindow->TagEdit->setText(sd.GetTag());
    modifyScheduleWindow->TimeEdit->setText(sd.GetTime());
    QHBoxLayout *layout = dynamic_cast<QHBoxLayout*>(modifyScheduleWindow->groupBox->layout());
    int flag=0;
    if(sd.GetTag()=="Shopping"||sd.GetTag()=="Workout"||sd.GetTag()=="Study"){
        for (int i = 0; i < layout->count(); ++i) {
            QRadioButton *radioButton = qobject_cast<QRadioButton*>(layout->itemAt(i)->widget());
            if (radioButton) {
                    if (radioButton->text()==sd.GetTag())
                        radioButton->setChecked(1);
            }
        }
    }
    else{
        for (int i = 0; i < layout->count(); ++i) {
            QRadioButton *radioButton = qobject_cast<QRadioButton*>(layout->itemAt(i)->widget());
            if (radioButton) {
                if (radioButton->text()==QString("Else"))
                    radioButton->setChecked(1);
                modifyScheduleWindow->TagEdit->setText(sd.GetTag());
                modifyScheduleWindow->TagEdit->show();
            }
        }

    }
    modifyScheduleWindow->show();
    connect(modifyScheduleWindow, &Modify_Schedule::scheduleClosed, this, &MainWindow::modify_handleScheduleClosed);
}

void MainWindow::ShowSchedule(QDate currentDate) {
    std::list<Schedule> DateList;
    for (auto s = schedulelist.begin(); s != schedulelist.end(); ++s)
        if (s->GetDate() == currentDate)
            DateList.push_back(*s);
    DateList.sort(compareFunc);
    if (ui->verticalLayout) {
        while (QLayoutItem *item = ui->verticalLayout->takeAt(0)) {  // 从布局中逐个移除部件
            QWidget *widget = item->widget();  // 获取部件
            if (widget) {
                ui->verticalLayout->removeWidget(widget);  // 从布局中移除部件
                delete widget;  // 删除部件
            }
            delete item;  // 删除布局项
        }
    }
    table = new QTableWidget(this);
    ui->verticalLayout->addWidget(table);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->clearContents();
    table->setRowCount(0);
    table->setColumnCount(5);
    // 隐藏水平表头
    table->horizontalHeader()->hide();
    // 逐个添加 schedulelist 中的每个 Schedule 条目到表格中
    int row = 0;
    for (auto schedule : DateList) {
        // 在表格中插入一行
        table->insertRow(row);
        QCheckBox *done = new QCheckBox();
        table->setCellWidget(row,0,done);
        table->setColumnWidth(0, 50); // 设置第一列宽度为50像素
        if (schedule.done())
            done->setChecked(true);
        else
            connect(done, &QCheckBox::stateChanged, [this,schedule] (int state) {
                on_CheckBox_statechanged(schedule, state);
            });
        // 创建单元格并设置内容
        QTableWidgetItem *taskItem = new QTableWidgetItem(schedule.GetTaskName());
        taskItem->setTextAlignment(Qt::AlignVCenter);
        // 将单元格添加到表格中
        table->setItem(row, 1, taskItem);
        QTableWidgetItem *TimeItem = new QTableWidgetItem(schedule.GetTime());
        TimeItem->setTextAlignment(Qt::AlignVCenter);
        table->setItem(row, 2, TimeItem);
        QPushButton *modifyButton = new QPushButton("Modify",this);
        connect(modifyButton, &QPushButton::clicked,[this,schedule](){
            on_Modify_Schedule_clicked(schedule);
        });
        table->setCellWidget(row,3,modifyButton);
        QPushButton *deleteButton = new QPushButton("Delete", this); // 创建删除按钮
        connect(deleteButton, &QPushButton::clicked, [this, schedule]() {
            on_Delete_Schedule_clicked(schedule); // 当按钮被点击时，调用删除日程的函数
        });
        table->setCellWidget(row, 4, deleteButton);
        if (schedule.done() == true) {
            QFont font = taskItem->font(); // 获取字体对象
            font.setStrikeOut(true); // 设置字体为被划掉效果
            taskItem->setFont(font);
            TimeItem->setFont(font);
        } else {
            if (schedule.GetTag() == "Study") {
                QColor skyblue(135, 206, 235);
                taskItem->setBackground(QBrush(skyblue));
                TimeItem->setBackground(QBrush(skyblue));
            }
            else if (schedule.GetTag() == "Workout") {
                QColor violetColor(238, 130, 238);
                taskItem->setBackground(QBrush(violetColor));
                TimeItem->setBackground(QBrush(violetColor));
            }
            else if (schedule.GetTag() == "Shopping") {
                QColor orangeColor(255, 165, 0);
                taskItem->setBackground(QBrush(orangeColor));
                TimeItem->setBackground(QBrush(orangeColor));
            }
        }

        row++;
    }
    table->show();
}

void MainWindow::ShowFourQuadrant(QDate tempdate) {

}

void MainWindow::on_BackToToday_clicked()
{
    calendar->setSelectedDate(QDate::currentDate());
    tempdate = QDate::currentDate();
    ShowSchedule(tempdate);
}

void MainWindow::onCalendarSelectionChanged() {
    tempdate = calendar->selectedDate();
    ShowSchedule(tempdate); // 更新日程显示
}

QDate MainWindow::GetTempDate() {
    return tempdate;
}

void MainWindow::on_CheckBox_statechanged(Schedule s, int state) {
    auto it = std::find(schedulelist.begin(), schedulelist.end(), s); // 开始时指向 list 的开始
    it->done() = (state==Qt::Checked);
    ShowSchedule(tempdate);
}

void MainWindow::updateTimer()
{
    QTime currentTime = QTime::currentTime();
    QString timeText = currentTime.toString("hh:mm");
    timerlabel->setText(timeText);
}

void MainWindow::del_handleScheduleClosed(){
    qDebug() << "delete schedule closed\n";
    qDebug() << schedulelist.size();
    for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
        qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
        qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
    }
    ShowSchedule(tempdate);
}

void MainWindow::handleScheduleClosed() {
    qDebug() << "add schedule closed\n";
    qDebug() << schedulelist.size();
    for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
        qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
        qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
        qDebug() << "Schedule Day: " << i->GetDate().toString();
    }
    ShowSchedule(tempdate);
}


void MainWindow::modify_handleScheduleClosed(){
    qDebug() << "modify schedule closed\n";
    qDebug() << schedulelist.size();
    for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
        qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
        qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
    }
    ui->label->show();
    ui->label_2->show();
    ShowSchedule(tempdate);
}

