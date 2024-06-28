/********************************************************************************
** Form generated from reading UI file 'Delete_Schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_SCHEDULE_H
#define UI_DELETE_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Delete_Schedule
{
public:
    QPushButton *del_confirmButton;
    QPushButton *del_concelButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Delete_Schedule)
    {
        if (Delete_Schedule->objectName().isEmpty())
            Delete_Schedule->setObjectName("Delete_Schedule");
        Delete_Schedule->resize(297, 152);
        del_confirmButton = new QPushButton(Delete_Schedule);
        del_confirmButton->setObjectName("del_confirmButton");
        del_confirmButton->setGeometry(QRect(30, 100, 80, 18));
        del_concelButton = new QPushButton(Delete_Schedule);
        del_concelButton->setObjectName("del_concelButton");
        del_concelButton->setGeometry(QRect(180, 100, 80, 18));
        textBrowser = new QTextBrowser(Delete_Schedule);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(40, 40, 221, 41));

        retranslateUi(Delete_Schedule);

        QMetaObject::connectSlotsByName(Delete_Schedule);
    } // setupUi

    void retranslateUi(QDialog *Delete_Schedule)
    {
        Delete_Schedule->setWindowTitle(QCoreApplication::translate("Delete_Schedule", "Dialog", nullptr));
        del_confirmButton->setText(QCoreApplication::translate("Delete_Schedule", "confirm", nullptr));
        del_concelButton->setText(QCoreApplication::translate("Delete_Schedule", "cancel", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Delete_Schedule", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\347\241\256\350\256\244\345\210\240\351\231\244\350\257\245\344\272\213\351\241\271\345\220\227\357\274\237</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete_Schedule: public Ui_Delete_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_SCHEDULE_H
