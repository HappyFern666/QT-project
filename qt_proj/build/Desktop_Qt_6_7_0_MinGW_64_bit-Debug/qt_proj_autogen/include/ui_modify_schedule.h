/********************************************************************************
** Form generated from reading UI file 'Modify_schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_SCHEDULE_H
#define UI_MODIFY_SCHEDULE_H

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

class Ui_Modify_Schedule
{
public:
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QPushButton *confirmButton;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QLabel *label_4;

    void setupUi(QDialog *Modify_Schedule)
    {
        if (Modify_Schedule->objectName().isEmpty())
            Modify_Schedule->setObjectName("Modify_Schedule");
        Modify_Schedule->resize(400, 300);
        label_2 = new QLabel(Modify_Schedule);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 180, 91, 16));
        lineEdit_3 = new QLineEdit(Modify_Schedule);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 130, 113, 23));
        label = new QLabel(Modify_Schedule);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 71, 16));
        lineEdit = new QLineEdit(Modify_Schedule);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 10, 251, 23));
        label_3 = new QLabel(Modify_Schedule);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 130, 61, 16));
        lineEdit_4 = new QLineEdit(Modify_Schedule);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(140, 230, 113, 23));
        confirmButton = new QPushButton(Modify_Schedule);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(300, 260, 80, 24));
        lineEdit_2 = new QLineEdit(Modify_Schedule);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(140, 180, 113, 23));
        groupBox = new QGroupBox(Modify_Schedule);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(39, 50, 331, 64));
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

        label_4 = new QLabel(Modify_Schedule);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 230, 54, 16));

        retranslateUi(Modify_Schedule);

        QMetaObject::connectSlotsByName(Modify_Schedule);
    } // setupUi

    void retranslateUi(QDialog *Modify_Schedule)
    {
        Modify_Schedule->setWindowTitle(QCoreApplication::translate("Modify_Schedule", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Modify_Schedule", "Planned time:", nullptr));
        label->setText(QCoreApplication::translate("Modify_Schedule", "*Task name:", nullptr));
        label_3->setText(QCoreApplication::translate("Modify_Schedule", "Input Tag:", nullptr));
        confirmButton->setText(QCoreApplication::translate("Modify_Schedule", "OK", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Modify_Schedule", "*Tag", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Modify_Schedule", "Shopping", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Modify_Schedule", "Workout", nullptr));
        radioButton->setText(QCoreApplication::translate("Modify_Schedule", "Study", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Modify_Schedule", "Else", nullptr));
        label_4->setText(QCoreApplication::translate("Modify_Schedule", "Notes:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modify_Schedule: public Ui_Modify_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_SCHEDULE_H
