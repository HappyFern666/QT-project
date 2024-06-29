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



MainWindow::MainWindow(std::list<Schedule> & schedulelist, QWidget *parent, QDate currentDate_)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , schedulelist(schedulelist)
    , currentDate(currentDate_)
    , tempdate(currentDate_)
{
    ui->setupUi(this);
    addScheduleWindow = new Add_Schedule(schedulelist,this);
    deleteScheduleWindow = new Delete_Schedule(schedulelist,this);
    modifyScheduleWindow = new Modify_Schedule(schedulelist,this);

    calendar = ui->calendarWidget;
    calendar->setSelectedDate(tempdate);
    connect(calendar, &QCalendarWidget::selectionChanged, this, &MainWindow::onCalendarSelectionChanged);


    ShowSchedule(tempdate);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    modify_layout = ui->verticalLayout_2;
}

MainWindow::~MainWindow()
{
    delete ui;
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
    DateList.sort();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    // 隐藏水平表头
    ui->tableWidget->horizontalHeader()->hide();
    // 逐个添加 schedulelist 中的每个 Schedule 条目到表格中
    int row = 0;
    for (auto schedule : DateList) {
        // 在表格中插入一行
        ui->tableWidget->insertRow(row);
        QCheckBox *done = new QCheckBox();
        ui->tableWidget->setCellWidget(row,0,done);
        ui->tableWidget->setColumnWidth(0, 50); // 设置第一列宽度为50像素
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
        ui->tableWidget->setItem(row, 1, taskItem);
        QTableWidgetItem *TimeItem = new QTableWidgetItem(schedule.GetTime());
        TimeItem->setTextAlignment(Qt::AlignVCenter);
        ui->tableWidget->setItem(row, 2, TimeItem);
        QPushButton *modifyButton = new QPushButton("Modify",this);
        connect(modifyButton, &QPushButton::clicked,[this,schedule](){
            on_Modify_Schedule_clicked(schedule);
        });
        ui->tableWidget->setCellWidget(row,3,modifyButton);
        QPushButton *deleteButton = new QPushButton("Delete", this); // 创建删除按钮
        connect(deleteButton, &QPushButton::clicked, [this, schedule]() {
            on_Delete_Schedule_clicked(schedule); // 当按钮被点击时，调用删除日程的函数
        });
        ui->tableWidget->setCellWidget(row, 4, deleteButton);
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
}

void MainWindow::on_BackToToday_clicked()
{
    calendar->setMinimumDate(startOfWeek);
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

