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
signals:
    void scheduleClosed();

public:
    explicit Add_Schedule(std::list<Schedule> & schedulelist, QWidget *parent = nullptr);
    ~Add_Schedule();

private slots:
    void on_confirmButton_clicked();

    void on_radioButton_3_clicked();

    void hideTagEdit() ;

private:
    Ui::Add_Schedule *ui;
    QLineEdit *lineEdit;
    QLineEdit *TimeEdit1;
    QLineEdit *TimeEdit2;
    QLineEdit *TagEdit;
    QLineEdit *NoteEdit;
    QGroupBox *groupBox;
    QPushButton *confirmButton;
    QRadioButton *ImpButton;
    QRadioButton *UrgButton;
    std::list<Schedule> & schedulelist;
};

#endif // ADD_SCHEDULE_H
