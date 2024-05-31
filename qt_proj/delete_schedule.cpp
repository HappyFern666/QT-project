#include "delete_schedule.h"
#include "ui_delete_schedule.h"
#include "Schedule.h"

#include <QtWidgets>
#include <QDebug>

Delete_Schedule::Delete_Schedule(std::list<Schedule> & schedulelist_, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Delete_Schedule)
    , schedulelist(schedulelist_)
{
    ui->setupUi(this);
    qDebug() << schedulelist.size();
    del_confirmButton = ui->del_confirmButton;
    connect(ui->del_confirmButton, &QPushButton::clicked, this, &Delete_Schedule::on_delete_confirmButton_clicked);
    connect(ui->del_concelButton,&QPushButton::clicked, this, &Delete_Schedule::on_cancelButton_clicked);
}
Delete_Schedule::~Delete_Schedule()
{
    delete ui;
}


void Delete_Schedule::on_delete_confirmButton_clicked()
{
    /*非常抱歉，不加这愚蠢的两行，on_confirmButton_clicked就会被完整执行两次。也不知道为什么。*/
    disconnect(ui->del_confirmButton, &QPushButton::clicked, this, &Delete_Schedule::on_delete_confirmButton_clicked);
    connect(ui->del_confirmButton, &QPushButton::clicked, this, &Delete_Schedule::on_delete_confirmButton_clicked);
    auto it = schedulelist.begin(); // 开始时指向 list 的开始
    std::advance(it, row); // 移动迭代器到指定的 row 位置

    // 从 schedulelist 中删除指定行的日程
    schedulelist.erase(it);
    // 然后更新表格
    //ui->tableWidget->removeRow(row);

    close();
    emit scheduleClosed();
}


void Delete_Schedule::on_cancelButton_clicked()
{

    close();
    emit scheduleClosed();
}

