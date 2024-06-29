#ifndef DELETE_SCHEDULE_H
#define DELETE_SCHEDULE_H

#include <QDialog>
#include <QtWidgets>
#include "Schedule.h"

namespace Ui {
class Delete_Schedule;
}

class Delete_Schedule : public QDialog
{
    Q_OBJECT
signals:
    void scheduleClosed();

public:

    explicit Delete_Schedule(std::list<Schedule> & schedulelist, QWidget *parent = nullptr);
    ~Delete_Schedule();

private slots:
    void on_delete_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Delete_Schedule *ui;
    QPushButton *del_confirmButton;
    QPushButton *del_concelButton;
    std::list<Schedule> & schedulelist;
    Schedule s;
    friend class MainWindow;
};

#endif // DELETE_SCHEDULE_H
