#include "modify_schedule.h"
#include "ui_modify_schedule.h"
#include "Schedule.h"

#include <QtWidgets>
#include <QDebug>

Modify_Schedule::Modify_Schedule(std::list<Schedule> & schedulelist_, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modify_Schedule)
    , schedulelist(schedulelist_)
{
    ui->setupUi(this);
    lineEdit = ui->lineEdit;
    TimeEdit = ui->lineEdit_2;
    TagEdit = ui->lineEdit_3;
    NoteEdit = ui->lineEdit_4;
    groupBox = ui->groupBox;
    qDebug() << schedulelist.size();
    confirmButton = ui->confirmButton;
    connect(ui->confirmButton, &QPushButton::clicked, this, &Modify_Schedule::on_modify_confirmButton_clicked);
    ui->label_3->hide();
    TagEdit->hide();

}
Modify_Schedule::~Modify_Schedule()
{
    delete ui;
}


void Modify_Schedule::on_modify_confirmButton_clicked()
{
    /*非常抱歉，不加这愚蠢的两行，on_confirmButton_clicked就会被完整执行两次。也不知道为什么。*/
    disconnect(ui->confirmButton, &QPushButton::clicked, this, &Modify_Schedule::on_modify_confirmButton_clicked);
    connect(ui->confirmButton, &QPushButton::clicked, this, &Modify_Schedule::on_modify_confirmButton_clicked);
    auto it = schedulelist.begin(); // 开始时指向 list 的开始
    std::advance(it, row); // 移动迭代器到指定的 row 位置

    // 从 schedulelist 中删除指定行的日程
    schedulelist.erase(it);
    QString userinput = lineEdit->text();
    QString TimeInput = TimeEdit->text();
    QString NoteInput = NoteEdit->text();
    QString selectedOption;
    // 检查每个 RadioButton 是否被选中，并确定用户选择了哪个选项
    // 获取 groupBox 的布局管理器
    QHBoxLayout *layout = dynamic_cast<QHBoxLayout*>(groupBox->layout());

    // 检查布局管理器是否存在
    if (layout) {

        // 遍历布局管理器中的控件，查找 RadioButton
        for (int i = 0; i < layout->count(); ++i) {
            QRadioButton *radioButton = qobject_cast<QRadioButton*>(layout->itemAt(i)->widget());
            if (radioButton) {
                if (radioButton->isChecked()) {
                    if (radioButton->text() == "Else") {
                        selectedOption = TagEdit->text();
                    } else {
                        selectedOption = radioButton->text();
                    }
                    radioButton->setChecked(false);
                }
            }
        }
    }
    if (userinput.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please input Task Name");
    }
    if (selectedOption.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please Select Tag");
    }
    Schedule schedule(userinput, selectedOption, TimeInput, NoteInput);
    // 将新创建的 Schedule 对象添加到 schedulelist 中
    schedulelist.push_back(schedule);
    ui->label_3->hide();
    TagEdit->hide();
    TagEdit->clear();
    lineEdit->clear();
    TimeEdit->clear();
    NoteEdit->clear();
    close();
    emit scheduleClosed();
}


void Modify_Schedule::on_modify_radioButton_3_clicked()
{
    ui->label_3->show();
    TagEdit->show();
}

