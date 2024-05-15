#include "mainwindow.h"

#include <QApplication>

class Schedule {
private:
    bool Done;
    int Time;
    std::string Name;
    std::string Place;
    Schedule* Subtasks[20];
    int Rating;
    int Tag;
    std::string Content;
public:
    std::string & setSchedule();
    bool doneSchedule();
};

class User {
private:
    std::string Id;
    Schedule* Tasks[50];
    std::string Password;
public:
    std::string & setId();
    std::string & setPassword();
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
