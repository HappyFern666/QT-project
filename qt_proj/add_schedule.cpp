#include "add_schedule.h"
#include "ui_add_schedule.h"
#include "Schedule.h"
#include "mainwindow.h"

#include <QtWidgets>
#include <QDebug>

Add_Schedule::Add_Schedule(std::list<Schedule> & schedulelist_, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_Schedule)
    , schedulelist(schedulelist_)
{
    ui->setupUi(this);
    lineEdit = ui->lineEdit;
    TimeEdit = ui->lineEdit_2;
    TagEdit = ui->lineEdit_3;
    NoteEdit = ui->lineEdit_4;
    groupBox = ui->groupBox;
    qDebug() << schedulelist.size();
    ImpButton = ui->radioButton_5;
    UrgButton = ui->radioButton_6;
    confirmButton = ui->confirmButton;
    connect(ui->confirmButton, &QPushButton::clicked, this, &Add_Schedule::on_confirmButton_clicked);
    ui->label_3->hide();
    TagEdit->hide();
    connect(ui->radioButton, &QPushButton::clicked, this, &Add_Schedule::hideTagEdit);
    connect(ui->radioButton_2, &QPushButton::clicked, this, &Add_Schedule::hideTagEdit);
    connect(ui->radioButton_4, &QPushButton::clicked, this, &Add_Schedule::hideTagEdit);
}
Add_Schedule::~Add_Schedule()
{
    delete ui;
}


void Add_Schedule::on_confirmButton_clicked()
{
    /*非常抱歉，不加这愚蠢的两行，on_confirmButton_clicked就会被完整执行两次。也不知道为什么。*/
    disconnect(ui->confirmButton, &QPushButton::clicked, this, &Add_Schedule::on_confirmButton_clicked);
    connect(ui->confirmButton, &QPushButton::clicked, this, &Add_Schedule::on_confirmButton_clicked);
    MainWindow *mw = qobject_cast<MainWindow *>(parentWidget());
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
        close();
        emit scheduleClosed();
        return;
    }
    if (selectedOption.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please Select Tag");
        close();
        emit scheduleClosed();
        return;
    }
    bool imp = ImpButton->isChecked();
    ImpButton->setChecked(false);
    bool Urg = UrgButton->isChecked();
    UrgButton->setChecked(false);
    int rat = 0;
    if (imp) {
        if (Urg) rat = 1;
        else rat = 2;
    } else {
        if (Urg) rat = 3;
        else rat = 4;
    }
    QDate d = mw->GetTempDate();
    Schedule schedule(userinput, selectedOption, TimeInput, NoteInput, d, rat);
    // 将新创建的 Schedule 对象添加到 schedulelist 中
    auto it = std::find(schedulelist.begin(), schedulelist.end(), schedule);

    // 检查元素是否被找到
    if (it != schedulelist.end()) {
        QMessageBox::warning(this, "Warning", "The task has been added to the list");
        close();
        emit scheduleClosed();
        return;
    }
    schedulelist.push_back(schedule);
    ui->label_3->hide();
    TagEdit->hide();
    TagEdit->clear();
    lineEdit->clear();
    TimeEdit->clear();
    NoteEdit->clear();
    close();
    emit scheduleClosed();
    mw->ShowSchedule(d);
}


void Add_Schedule::on_radioButton_3_clicked()
{
    ui->label_3->show();
    TagEdit->show();
}

void Add_Schedule::hideTagEdit() {
    ui->label_3->hide();
    TagEdit->hide();
}

