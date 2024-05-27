#include "Schedule.h"

QString & Schedule::GetTaskName() {
    return TaskName;
}

QString & Schedule::GetTag() {
    return Tag;
}

QString & Schedule::GetContent() {
    return Content;
}

QString & Schedule::GetTime() {
    return Time;
}

bool Schedule::operator< (const Schedule & b) {
    if (Time[0] != b.Time[0]) return Time[0] < b.Time[0];
    if (Time[1] != b.Time[1]) return Time[1] < b.Time[1];
    if (Time[3] != b.Time[3]) return Time[3] < b.Time[3];
    return Time[4] < b.Time[4];
}