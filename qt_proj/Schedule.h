#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QString>

class Schedule {
private:
    bool Done;
    QString Time;
    QString TaskName;
    QString Place;
    Schedule* Subtasks[20];
    int Rating;
    QString Tag;
    QString Content;
public:
    Schedule(const QString& name_, const QString& tag_, const QString & Time_ , const QString & Note_): TaskName(name_), Tag(tag_), Time(Time_), Content(Note_) {}
    bool doneSchedule();
    QString & GetTaskName();
    QString & GetTag();
    QString & GetTime();
    QString & GetContent();
    bool operator< (const Schedule & b);
};

#endif // SCHEDULE_H
