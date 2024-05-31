#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add_schedule.h"
#include "delete_schedule.h"
#include "modify_schedule.h"
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
    void handleScheduleClosed() {
        qDebug() << "add schedule closed\n";
        qDebug() << schedulelist.size();
        for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
            qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
            qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
        }


        ShowSchedule();
    }
    void del_handleScheduleClosed(){
        qDebug() << "delete schedule closed\n";
        qDebug() << schedulelist.size();
        for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
            qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
            qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
        }


        ShowSchedule();
    }
    void modify_handleScheduleClosed(){
        qDebug() << "modify schedule closed\n";
        qDebug() << schedulelist.size();
        for (auto i = schedulelist.begin(); i!=schedulelist.end(); ++i) {
            qDebug() << "Schedule Name: " << i->GetTaskName() << "Schedule Tag: " << i->GetTag();
            qDebug() << "Schedule Time: " << i->GetTime() << "Schedule Content: " << i->GetContent();
        }


        ShowSchedule();
    }
    void on_Delete_Schedule_clicked(int row);
    void on_Modify_Schedule_clicked(int row);

private:
    Ui::MainWindow *ui;
    std::list<Schedule> & schedulelist;
    Add_Schedule *addScheduleWindow;
    Delete_Schedule *deleteScheduleWindow;
    Modify_Schedule *modifyScheduleWindow;

};
#endif // MAINWINDOW_H
