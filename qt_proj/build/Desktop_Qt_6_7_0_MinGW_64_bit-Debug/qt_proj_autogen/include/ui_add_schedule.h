/********************************************************************************
** Form generated from reading UI file 'add_schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_SCHEDULE_H
#define UI_ADD_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Add_Schedule
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QPushButton *confirmButton;

    void setupUi(QDialog *Add_Schedule)
    {
        if (Add_Schedule->objectName().isEmpty())
            Add_Schedule->setObjectName("Add_Schedule");
        Add_Schedule->resize(400, 300);
        lineEdit = new QLineEdit(Add_Schedule);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 60, 251, 23));
        label = new QLabel(Add_Schedule);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 60, 71, 16));
        groupBox = new QGroupBox(Add_Schedule);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(29, 100, 331, 71));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(10, 30, 97, 22));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(100, 30, 97, 22));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(210, 30, 97, 22));
        confirmButton = new QPushButton(Add_Schedule);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(290, 260, 80, 24));

        retranslateUi(Add_Schedule);

        QMetaObject::connectSlotsByName(Add_Schedule);
    } // setupUi

    void retranslateUi(QDialog *Add_Schedule)
    {
        Add_Schedule->setWindowTitle(QCoreApplication::translate("Add_Schedule", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Add_Schedule", "Task name:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Add_Schedule", "Tag", nullptr));
        radioButton->setText(QCoreApplication::translate("Add_Schedule", "Study", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Add_Schedule", "Workout", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Add_Schedule", "Shopping", nullptr));
        confirmButton->setText(QCoreApplication::translate("Add_Schedule", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Schedule: public Ui_Add_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_SCHEDULE_H
