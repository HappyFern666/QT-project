#ifndef MODIFY_SCHEDULE_H
#define MODIFY_SCHEDULE_H

#include <QDialog>
#include <QtWidgets>
#include "Schedule.h"

namespace Ui {
    class Modify_Schedule;
}

class Modify_Schedule : public QDialog
{
    Q_OBJECT
signals:
    void scheduleClosed();

public:
    int row;
    explicit Modify_Schedule(std::list<Schedule> & schedulelist, QWidget *parent = nullptr, QDate currentDate_ = QDate::currentDate());
    ~Modify_Schedule();

private slots:
    void on_modify_confirmButton_clicked();

    void on_modify_radioButton_3_clicked();

private:
    Ui::Modify_Schedule *ui;
    QLineEdit *lineEdit;
    QLineEdit *TimeEdit;
    QLineEdit *TagEdit;
    QLineEdit *NoteEdit;
    QGroupBox *groupBox;
    QPushButton *confirmButton;
    std::list<Schedule> & schedulelist;
    friend class MainWindow;
    QDate currentDate;
    QRadioButton *delayButton;
};

#endif // MODIFY_SCHEDULE_H
