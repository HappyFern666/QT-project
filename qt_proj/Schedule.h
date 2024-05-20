#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QString>

class Schedule {
private:
    bool Done;
    int Time;
    QString TaskName;
    QString Place;
    Schedule* Subtasks[20];
    int Rating;
    QString Tag;
    std::string Content;
public:
    Schedule(const QString& name_, const QString& tag_ ): TaskName(name_), Tag(tag_) {}
    bool doneSchedule();
};

#endif // SCHEDULE_H
