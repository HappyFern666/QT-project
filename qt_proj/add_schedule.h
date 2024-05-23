#ifndef ADD_SCHEDULE_H
#define ADD_SCHEDULE_H

#include <QDialog>
#include <QtWidgets>
#include "Schedule.h"

namespace Ui {
class Add_Schedule;
}

class Add_Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Schedule(std::list<Schedule> *schedulelist, QWidget *parent = nullptr);
    ~Add_Schedule();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::Add_Schedule *ui;
    QLineEdit *lineEdit;
    QGroupBox *groupBox;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QPushButton *confirmButton;
    std::list<Schedule> *schedulelist;
};

#endif // ADD_SCHEDULE_H
