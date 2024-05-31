/********************************************************************************
** Form generated from reading UI file 'Add_Schedule.ui'
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
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QPushButton *confirmButton;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;

    void setupUi(QDialog *Add_Schedule)
    {
        if (Add_Schedule->objectName().isEmpty())
            Add_Schedule->setObjectName("Add_Schedule");
        Add_Schedule->resize(391, 346);
        lineEdit = new QLineEdit(Add_Schedule);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 60, 251, 23));
        label = new QLabel(Add_Schedule);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 60, 71, 16));
        groupBox = new QGroupBox(Add_Schedule);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(29, 100, 331, 64));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName("radioButton_4");

        horizontalLayout->addWidget(radioButton_4);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");

        horizontalLayout->addWidget(radioButton);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");

        horizontalLayout->addWidget(radioButton_3);

        confirmButton = new QPushButton(Add_Schedule);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(290, 310, 80, 24));
        lineEdit_2 = new QLineEdit(Add_Schedule);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 230, 113, 23));
        label_2 = new QLabel(Add_Schedule);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 230, 91, 16));
        lineEdit_3 = new QLineEdit(Add_Schedule);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(130, 180, 113, 23));
        label_3 = new QLabel(Add_Schedule);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 180, 61, 16));
        lineEdit_4 = new QLineEdit(Add_Schedule);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(130, 280, 113, 23));
        label_4 = new QLabel(Add_Schedule);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 280, 54, 16));

        retranslateUi(Add_Schedule);

        QMetaObject::connectSlotsByName(Add_Schedule);
    } // setupUi

    void retranslateUi(QDialog *Add_Schedule)
    {
        Add_Schedule->setWindowTitle(QCoreApplication::translate("Add_Schedule", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Add_Schedule", "*Task name:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Add_Schedule", "*Tag", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Add_Schedule", "Shopping", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Add_Schedule", "Workout", nullptr));
        radioButton->setText(QCoreApplication::translate("Add_Schedule", "Study", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Add_Schedule", "Else", nullptr));
        confirmButton->setText(QCoreApplication::translate("Add_Schedule", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("Add_Schedule", "Planned time:", nullptr));
        label_3->setText(QCoreApplication::translate("Add_Schedule", "Input Tag:", nullptr));
        label_4->setText(QCoreApplication::translate("Add_Schedule", "Notes:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Schedule: public Ui_Add_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_SCHEDULE_H
