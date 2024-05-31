#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Schedule.h"
#include "add_schedule.h"
#include "delete_schedule.h"
#include "modify_schedule.h"
#include <QtWidgets>
#include <QtUiTools/QUiLoader>
#include <QFile>

MainWindow::MainWindow(std::list<Schedule> & schedulelist, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , schedulelist(schedulelist)
{
    ui->setupUi(this);
    addScheduleWindow = new Add_Schedule(schedulelist,this);
    deleteScheduleWindow = new Delete_Schedule(schedulelist,this);
    modifyScheduleWindow = new Modify_Schedule(schedulelist,this);
    ShowSchedule();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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


void MainWindow::on_Delete_Schedule_clicked(int row)
{
    qDebug() << "Delete Schedule opened\n";
    qDebug() << schedulelist.size();
    deleteScheduleWindow->row=row;
    deleteScheduleWindow->show();
    connect(deleteScheduleWindow, &Delete_Schedule::scheduleClosed, this, &MainWindow::del_handleScheduleClosed);
}
void MainWindow::on_Modify_Schedule_clicked(int row){
    qDebug() << "Modify Schedule opened\n";
    qDebug() << schedulelist.size();
    modifyScheduleWindow->row=row;
    auto it = schedulelist.begin(); // 开始时指向 list 的开始

    std::advance(it, row);
    modifyScheduleWindow->lineEdit->setText(it->GetTaskName());
    modifyScheduleWindow->NoteEdit->setText(it->GetContent());
    modifyScheduleWindow->TagEdit->setText(it->GetTag());
    modifyScheduleWindow->TimeEdit->setText(it->GetTime());
    QHBoxLayout *layout = dynamic_cast<QHBoxLayout*>(modifyScheduleWindow->groupBox->layout());
    int flag=0;
    if(it->GetTag()=="Shopping"||it->GetTag()=="Workout"||it->GetTag()=="Study"){
        for (int i = 0; i < layout->count(); ++i) {
            QRadioButton *radioButton = qobject_cast<QRadioButton*>(layout->itemAt(i)->widget());
            if (radioButton) {
                    if (radioButton->text()==it->GetTag())
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
                modifyScheduleWindow->TagEdit->setText(it->GetTag());
                modifyScheduleWindow->TagEdit->show();
            }
        }

    }
    modifyScheduleWindow->show();
    connect(modifyScheduleWindow, &Modify_Schedule::scheduleClosed, this, &MainWindow::modify_handleScheduleClosed);
}

void MainWindow::ShowSchedule() {
    schedulelist.sort();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    // 隐藏水平表头
    ui->tableWidget->horizontalHeader()->hide();
    // 逐个添加 schedulelist 中的每个 Schedule 条目到表格中
    int row = 0;
    for (auto & schedule : schedulelist) {
        // 在表格中插入一行
        ui->tableWidget->insertRow(row);
        QCheckBox *done = new QCheckBox();
        ui->tableWidget->setCellWidget(row,0,done);
        // 创建单元格并设置内容
        QTableWidgetItem *taskItem = new QTableWidgetItem(schedule.GetTaskName());
        taskItem->setTextAlignment(Qt::AlignVCenter);
        // 将单元格添加到表格中
        ui->tableWidget->setItem(row, 1, taskItem);
        QTableWidgetItem *TimeItem = new QTableWidgetItem(schedule.GetTime());
        TimeItem->setTextAlignment(Qt::AlignVCenter);
        ui->tableWidget->setItem(row, 2, TimeItem);
        QPushButton *modifyButton = new QPushButton("Modify",this);
        connect(modifyButton, &QPushButton::clicked,[this,row](){
            on_Modify_Schedule_clicked(row);
        });
        ui->tableWidget->setCellWidget(row,3,modifyButton);
        QPushButton *deleteButton = new QPushButton("Delete", this); // 创建删除按钮
        connect(deleteButton, &QPushButton::clicked, [this, row]() {
            on_Delete_Schedule_clicked(row); // 当按钮被点击时，调用删除日程的函数
        });
        ui->tableWidget->setCellWidget(row, 4, deleteButton);

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
        row++;
    }
}
