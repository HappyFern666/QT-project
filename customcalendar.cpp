#include "customcalendar.h"
#include <QApplication>
#include <QCalendarWidget>
#include <QHeaderView>
#include <QLabel>
#include <QHBoxLayout>
#include <QTableView>
#include <QToolButton>
#include <QObject>

void CustomCalendar::replaceHeader() {
    setNavigationBarVisible(false);
    // 获取默认的标题栏部件（QTableView）
    QTableView *table = findChild<QTableView *>();
    if (!table) return;

    // 创建自定义的标题栏部件
    QHeaderView *customHeader = new QHeaderView(Qt::Horizontal);
    customHeader->setSectionResizeMode(QHeaderView::Stretch); // 拉伸模式填充整个标题栏
    QHBoxLayout *layout = new QHBoxLayout(customHeader);
    QStringList weekDays = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    // 添加星期几的标签到自定义标题栏
    for (int i = 0; i < weekDays.size(); ++i) {
        QLabel *dayLabel = new QLabel(weekDays[i], customHeader);
        dayLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(dayLabel);
    }

    // 设置自定义标题栏部件到标题栏
    table->horizontalHeader()->setVisible(false);
    table->setHorizontalHeader(customHeader);
}

void CustomCalendar::setupNavigationButtons() {
    // 获取默认的导航按钮
    QToolButton *nextMonthButton = findChild<QToolButton*>("qt_calendar_prevmonth");
    QToolButton *prevMonthButton = findChild<QToolButton*>("qt_calendar_nextmonth");

    if (nextMonthButton) {
        // 替换右侧箭头按钮的点击事件
        nextMonthButton->disconnect();  // 首先断开原有的连接
        connect(nextMonthButton, &QToolButton::clicked, [=]() {
            showNextWeek();
        });
    }

    if (prevMonthButton) {
        // 如果需要，你也可以替换左侧箭头按钮的点击事件
        prevMonthButton->disconnect();
        connect(prevMonthButton, &QToolButton::clicked, [=]() {
            showPreviousWeek();
        });
    }
}

void CustomCalendar::showNextWeek() {
    QDate currentDate = selectedDate();
    QDate nextWeekStartDate = currentDate.addDays(7 - currentDate.dayOfWeek());
    setSelectedDate(nextWeekStartDate);
}

void CustomCalendar::showPreviousWeek() {
    QDate currentDate = selectedDate();
    QDate prevWeekStartDate = currentDate.addDays(-currentDate.dayOfWeek() - 6);
    setSelectedDate(prevWeekStartDate);
}

