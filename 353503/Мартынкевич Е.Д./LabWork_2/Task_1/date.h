#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QRegularExpression>

class Date
{
public:
    Date(QString string_date);
    void checkDay(int, int, int);
    int daysInMonth(int, int);
    bool isLeapYear(int);
    QString DayOfWeekString();

    Date previousDay();
    short weekNumber();
    short dayOfWeek();
    short dayOfYear();
    int daysTillYourBithday(Date bithdaydate);
    int duration (Date date, bool sign=false);
    Date nextDay();
    int getDay();
    int getYear();
    int getMonth();

    bool is_correct_date = true;
    QString day_string;

private:

    int day;
    int month;
    int year;
};

#endif // DATE_H
