#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Schedule.h"
#include "add_schedule.h"
#include <QtWidgets>
#include <QtUiTools/QUiLoader>
#include <QFile>

MainWindow::MainWindow(std::list<Schedule> *schedulelist, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , schedulelist(schedulelist)
{
    ui->setupUi(this);
    addScheduleWindow = new Add_Schedule(schedulelist,this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Add_Schedule_clicked()
{

    addScheduleWindow->show();
}

