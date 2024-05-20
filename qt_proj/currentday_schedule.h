#ifndef CURRENTDAY_SCHEDULE_H
#define CURRENTDAY_SCHEDULE_H

#include <QDialog>

namespace Ui {
class CurrentDay_Schedule;
}

class CurrentDay_Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentDay_Schedule(QWidget *parent = nullptr);
    ~CurrentDay_Schedule();

private:
    Ui::CurrentDay_Schedule *ui;
};

#endif // CURRENTDAY_SCHEDULE_H
