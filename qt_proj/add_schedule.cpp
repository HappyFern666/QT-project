#include "add_schedule.h"
#include "ui_add_schedule.h"
#include "Schedule.h"

#include <QtWidgets>

Add_Schedule::Add_Schedule(std::list<Schedule> *schedulelist, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_Schedule)
{
    ui->setupUi(this);
    lineEdit = ui->lineEdit;
    groupBox = ui->groupBox;

    radioButton1 = groupBox->findChild<QRadioButton*>("radioButton1");
    radioButton2 = groupBox->findChild<QRadioButton*>("radioButton2");
    radioButton3 = groupBox->findChild<QRadioButton*>("radioButton3");

    confirmButton = groupBox->findChild<QPushButton*>("confirmButton");
    connect(ui->confirmButton, &QPushButton::clicked, this, &Add_Schedule::on_confirmButton_clicked);
}
Add_Schedule::~Add_Schedule()
{
    delete ui;
}


void Add_Schedule::on_confirmButton_clicked()
{
    QString userinput = lineEdit->text();
    QString selectedOption;
    // 检查每个 RadioButton 是否被选中，并确定用户选择了哪个选项
    if (radioButton1->isChecked()) {
        selectedOption = "Study";
    } else if (radioButton2->isChecked()) {
        selectedOption = "Workout";
    } else if (radioButton3->isChecked()) {
        selectedOption = "Shopping";
    } else {
        selectedOption = "No option selected";
    }
    Schedule schedule(userinput, selectedOption);

    // 将新创建的 Schedule 对象添加到 schedulelist 中
    schedulelist->push_back(schedule);
    close();
}

