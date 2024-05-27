#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add_schedule.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::list<Schedule> & schedulelist_, QWidget *parent = nullptr);
    ~MainWindow();
    void ShowSchedule();

private slots:
    void on_Add_Schedule_clicked();
    void handleScheduleClosed();

private:
    Ui::MainWindow *ui;
    std::list<Schedule> & schedulelist;
    Add_Schedule *addScheduleWindow;

};
#endif // MAINWINDOW_H
