#ifndef DATE_H
#define DATE_H

#include <QString>
class Date
{
public:
    Date() : day(0), month(0), year(0) {}
    explicit Date(QString date);
    Date(int day, int month, int year);
    short GetDay();
    short GetMonth();
    short GetYear();
    void SetYear(short);
    void SetMonth(short);
    void SetDay(short);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBithday(Date);
    int Duration(Date);
    QString ToQString();

private:
    int day, month, year;
    short dayOfWeekOfYearBegin(short);
    bool isLeap(short);
    int duration(Date, Date);
};

#endif // DATE_H
