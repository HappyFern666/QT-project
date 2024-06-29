#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QString>
#include <QDate>

class Schedule {
private:
    bool Done = false;
    QString Time;
    QString TaskName;
    QString Place;
    int Rating;
    QString Tag;
    QString Content;
    QDate Date;
public:
    Schedule() {}
    Schedule(const QString& name_, const QString& tag_, const QString & Time_ , const QString & Note_, const QDate & currentDate, int rat): TaskName(name_), Tag(tag_), Time(Time_), Content(Note_), Date(currentDate), Rating(rat) {}
    bool & done();
    QString & GetTaskName();
    QString & GetTag();
    QString & GetTime();
    QString & GetContent();
    QDate & GetDate();
    int & GetRating();
    bool operator< (const Schedule & b);
    bool operator== (const Schedule b) ;
};

#endif // SCHEDULE_H
