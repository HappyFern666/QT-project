#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "add_schedule.h"
#include "delete_schedule.h"
#include "modify_schedule.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::list<Schedule> & schedulelist_, QWidget *parent = nullptr, QDate currentDate = QDate::currentDate());
    ~MainWindow();
    void ShowSchedule(QDate currentDate);
    void ShowFourQuadrant(QDate currentDate);
    QDate GetTempDate();

private slots:
    void on_Add_Schedule_clicked();
    void handleScheduleClosed() ;
    void del_handleScheduleClosed();
    void modify_handleScheduleClosed();
    void on_Delete_Schedule_clicked(Schedule sd);
    void on_Modify_Schedule_clicked(Schedule sd);

    void on_BackToToday_clicked();

    void onCalendarSelectionChanged();

    void on_CheckBox_statechanged(Schedule s, int state);

    void updateTimer();

private:


    Ui::MainWindow *ui;
    std::list<Schedule> & schedulelist;
    Add_Schedule *addScheduleWindow;
    Delete_Schedule *deleteScheduleWindow;
    Modify_Schedule *modifyScheduleWindow;

    QDate currentDate;

    QVBoxLayout *modify_layout;
    QCalendarWidget *calendar;

    QDate tempdate;

    QLabel *background;
    QTimer *timer;
    QLabel *timerlabel;
    QImage image;

    QTableWidget *table;
    QTableWidget *importantUrgent;
    QTableWidget *importantNotUrgent;
    QTableWidget *notImportantUrgent;
    QTableWidget *notImportantNotUrgent;
};
#endif // MAINWINDOW_H
