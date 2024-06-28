#ifndef CUSTOMCALENDAR_H
#define CUSTOMCALENDAR_H


#include <QApplication>
#include <QCalendarWidget>
#include <QHeaderView>
#include <QLabel>
#include <QHBoxLayout>
#include <QTableView>
#include <QToolButton>

class CustomCalendar: public QCalendarWidget
{
public:
    CustomCalendar(QWidget *parent = nullptr) : QCalendarWidget(parent) {
        replaceHeader();
        setupNavigationButtons();
    }
protected:
    void replaceHeader();
    void setupNavigationButtons();

    void showNextWeek() ;

    void showPreviousWeek() ;
};

Q_DECLARE_METATYPE(CustomCalendar*);

#endif // CUSTOMCALENDAR_H
