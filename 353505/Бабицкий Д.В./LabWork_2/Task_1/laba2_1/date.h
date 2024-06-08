#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QDate>

#include<cstdlib>
class Date
{
private:
    int year=0;
    int day=0;
    int month=0;
    int days[12] {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    Date(int dayd,int monthd,int yeard );
    void create(QString s);
    bool Isleap();
    Date NextDay();
    Date PreviousDay();
    short WeekNumber();
    int DateTillYourBirthday(Date birthday);
    int Duration(Date date);
    QString output_string(Date date);
    QString outp_n(Date date);
    QString outp(Date date);
    QString output();
    QString output_string_1(Date);
};

#endif // DATE_H
