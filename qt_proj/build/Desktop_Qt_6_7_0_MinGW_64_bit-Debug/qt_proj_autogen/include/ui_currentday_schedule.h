/********************************************************************************
** Form generated from reading UI file 'currentday_schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTDAY_SCHEDULE_H
#define UI_CURRENTDAY_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CurrentDay_Schedule
{
public:

    void setupUi(QDialog *CurrentDay_Schedule)
    {
        if (CurrentDay_Schedule->objectName().isEmpty())
            CurrentDay_Schedule->setObjectName("CurrentDay_Schedule");
        CurrentDay_Schedule->resize(400, 300);

        retranslateUi(CurrentDay_Schedule);

        QMetaObject::connectSlotsByName(CurrentDay_Schedule);
    } // setupUi

    void retranslateUi(QDialog *CurrentDay_Schedule)
    {
        CurrentDay_Schedule->setWindowTitle(QCoreApplication::translate("CurrentDay_Schedule", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentDay_Schedule: public Ui_CurrentDay_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTDAY_SCHEDULE_H
