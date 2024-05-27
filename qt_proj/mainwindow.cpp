#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Schedule.h"
#include "add_schedule.h"
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
    ShowSchedule();
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

void MainWindow::handleScheduleClosed() {
    qDebug() << "add schedule closed\n";
    qDebug() << schedulelist.size();
    for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
        qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
        qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
    }


    ShowSchedule();
}

void MainWindow::ShowSchedule() {
    schedulelist.sort();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    // 隐藏水平表头
    ui->tableWidget->horizontalHeader()->hide();
    // 逐个添加 schedulelist 中的每个 Schedule 条目到表格中
    int row = 0;
    for (auto & schedule : schedulelist) {
        // 在表格中插入一行
        ui->tableWidget->insertRow(row);

        // 创建单元格并设置内容
        QTableWidgetItem *taskItem = new QTableWidgetItem(schedule.GetTaskName());
        taskItem->setTextAlignment(Qt::AlignVCenter);
        // 将单元格添加到表格中
        ui->tableWidget->setItem(row, 0, taskItem);
        QTableWidgetItem *TimeItem = new QTableWidgetItem(schedule.GetTime());
        TimeItem->setTextAlignment(Qt::AlignVCenter);
        ui->tableWidget->setItem(row, 1, TimeItem);

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
