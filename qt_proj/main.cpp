#include "mainwindow.h"
#include "Schedule.h"
#include "User.h"
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    User Current_User();


    w.show();

    return a.exec();
}
