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

QDate & Schedule::GetDate() {
    return Date;
}

bool Schedule::Compare1(const Schedule& a, const Schedule& b) {
    // 比较 Time 数组中的元素
    for (size_t i = 0; i < a.Time.size() && i < b.Time.size(); ++i) {
        if (a.Time[i] != b.Time[i]) {
            return a.Time[i] < b.Time[i];
        }
    }
    return Schedule::Compare2(a,b);
}
bool Schedule::Compare2(const Schedule& a, const Schedule& b) {
    if(a.Rating!=b.Rating)
    return a.Rating<b.Rating;
    return Schedule::Compare1(a,b);
}

bool Schedule::operator< (const Schedule & b) {
    if (Time.isEmpty()) return false;
    if (b.Time.isEmpty()) return true;
    if (Time[0] != b.Time[0]) return Time[0] < b.Time[0];
    if (Time[1] != b.Time[1]) return Time[1] < b.Time[1];
    if (Time[3] != b.Time[3]) return Time[3] < b.Time[3];
    return Time[4] < b.Time[4];
}

bool & Schedule::done() {
    return Done;
}

bool Schedule::operator== (Schedule b) {
    return TaskName == b.GetTaskName() && Tag == b.GetTag() && Time == b.GetTime();
}

int & Schedule::GetRating() {
    return Rating;
}
