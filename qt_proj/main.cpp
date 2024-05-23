#include "mainwindow.h"
#include "Schedule.h"
#include "User.h"
#include <QtWidgets>
#include <list>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User Current_User;
    MainWindow w(Current_User.getTaskList());
    w.show();

    return a.exec();
}
