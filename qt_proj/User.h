#ifndef USER_H
#define USER_H

#include <QString>
#include "Schedule.h"
#include <list>

class User {
private:
    QString Id;
    QString Password;
    std::list<Schedule> *TaskList;
public:
    User() {}
    QString & setId();
    QString & setPassword();
    std::list<Schedule>* getTaskList();
};

#endif // USER_H
