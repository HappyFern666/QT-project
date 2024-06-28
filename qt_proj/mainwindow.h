#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "add_schedule.h"
#include "delete_schedule.h"
#include "modify_schedule.h"
#include "CustomCalendar.h"

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
    QDate GetTempDate();

private slots:
    void on_Add_Schedule_clicked();
    void handleScheduleClosed() {
        qDebug() << "add schedule closed\n";
        qDebug() << schedulelist.size();
        for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
            qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
            qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
            qDebug() << "Schedule Day: " << i->GetDate().toString();
        }
        ShowSchedule(tempdate);
    }
    void del_handleScheduleClosed(){
        qDebug() << "delete schedule closed\n";
        qDebug() << schedulelist.size();
        for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
            qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
            qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
        }

        ShowSchedule(tempdate);
    }
    void modify_handleScheduleClosed(){
        qDebug() << "modify schedule closed\n";
        qDebug() << schedulelist.size();
        for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
            qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
            qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
        }


        ShowSchedule(tempdate);
    }
    void on_Delete_Schedule_clicked(int row);
    void on_Modify_Schedule_clicked(int row);

    void on_BackToToday_clicked();

    void onCalendarSelectionChanged();

    void on_CheckBox_statechanged(int row);

private:
    Ui::MainWindow *ui;
    std::list<Schedule> & schedulelist;
    Add_Schedule *addScheduleWindow;
    Delete_Schedule *deleteScheduleWindow;
    Modify_Schedule *modifyScheduleWindow;
    QDate currentDate;
    QVBoxLayout *modify_layout;
    QString calendar_style_sheet;
    QDate startOfWeek;
    QCalendarWidget *calendar;
    QDate tempdate;
};
#endif // MAINWINDOW_H
