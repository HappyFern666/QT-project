#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Schedule.h"
#include <QDialog>
#include <QLineEdit>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Add_new_schedule, &QPushButton::clicked, this, &MainWindow::on_Add_new_schedule_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_new_schedule_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
    //输入任务名称
    QLineEdit *inputTaskName = new QLineEdit(dialog);

    QGroupBox * groupBox = new QGroupBox(tr("Tag: "),dialog);
    QHBoxLayout * layout_cat = new QHBoxLayout(dialog);

    QRadioButton *radioButton1 = new QRadioButton("study");
    layout_cat->addWidget(radioButton1);
    QRadioButton *radioButton2 = new QRadioButton("workout");
    layout_cat->addWidget(radioButton2);
    QRadioButton *radioButton3 = new QRadioButton("shopping");
    layout_cat->addWidget(radioButton3);

    QButtonGroup *buttonGroup = new QButtonGroup(dialog);
    buttonGroup->addButton(radioButton1);
    buttonGroup->addButton(radioButton2);
    buttonGroup->addButton(radioButton3);

    radioButton1->setChecked(true);
    groupBox->setLayout(layout_cat);

    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->addWidget(inputTaskName);
    dialogLayout->addWidget(groupBox);
    dialog->setLayout(dialogLayout);

    QPushButton *okButton = new QPushButton("OK", dialog);
    connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);  // 连接点击事件到对话框的 accept 槽函数
    dialogLayout->addWidget(okButton);

    int result = dialog->exec();
    if (result == QDialog::Accepted) {

        QString taskName = inputTaskName->text();
        QString tagName;
        QAbstractButton *checkedButton = buttonGroup->checkedButton();
        if (checkedButton) {
            tagName = checkedButton->text();
            // 在这里进行任务处理或者其他操作
            // 其他处理...
        }
        Schedule* newschedule = new Schedule(taskName, tagName);
    }
    dialog->close();
}

