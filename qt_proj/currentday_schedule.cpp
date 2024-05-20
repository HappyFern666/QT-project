#include "currentday_schedule.h"
#include "ui_currentday_schedule.h"

CurrentDay_Schedule::CurrentDay_Schedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CurrentDay_Schedule)
{
    ui->setupUi(this);
}

CurrentDay_Schedule::~CurrentDay_Schedule()
{
    delete ui;
}
