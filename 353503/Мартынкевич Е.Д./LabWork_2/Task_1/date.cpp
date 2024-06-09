#include "date.h"

Date::Date(QString string_date) {

    QRegularExpression expression("(\\d{2})\\.(\\d{2})\\.(\\d{4})");
    QRegularExpressionMatch match_exp = expression.match(string_date);

    if (match_exp.hasMatch()) {
        int day = match_exp.captured(1).toInt();
        int month = match_exp.captured(2).toInt();
        int year = match_exp.captured(3).toInt();

        checkDay(day, month, year);
    }
    else {
        this->is_correct_date = false;
    }

    if(is_correct_date){
        day_string = string_date;
    }
}

void Date::checkDay(int day, int month, int year)
{
    if (year > 9999 || year < 0) {
        this->year = -1;
        this->is_correct_date = false;
    }
    else {
        this->year = year;
    }

    if (month > 12 || month < 1) {
        this->month = -1;
        this->is_correct_date = false;
    }
    else {
        this->month = month;
    }

    if (day > daysInMonth(month, year) || day < 1) {
        this->day = -1;
        this->is_correct_date = false;
    }
    else {
        this->day = day;
    }
}

int Date::daysInMonth(int month, int year)
{
    QSet<int> day1 = {1, 3, 5, 7, 8, 10, 12};

    if (month == 2) {
        return (isLeapYear(year) ? 29 : 28);
    } else if (day1.contains(month)) {
        return 31;
    } else {
        return 30;
    }
}

bool Date::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

QString Date::DayOfWeekString()
{
    switch (dayOfWeek()) {
    case 0:
        return "Воскресенье";
    case 1:
        return "Понедельник";
    case 2:
        return "Вторник";
    case 3:
        return "Среда";
    case 4:
        return "Четверг";
    case 5:
        return "Пятница";
    case 6:
        return "Суббота";
    default:
        return "эрор";
    }
}

Date Date::nextDay() {
    int new_day = this->day;
    int new_month = this->month;
    int new_year = this->year;

    if (new_year == 9999 && new_month == 12 && new_day == 31) {
        return Date(QString("01.01.0000"));
    }

    if (new_day == 31 && new_month == 12) {
        new_year++;
        new_month = 1;
        new_day = 1;
    } else if (new_day == daysInMonth(new_month, new_year)) {
        new_month++;
        new_day = 1;
    } else {
        new_day++;
    }

    return Date(QString("%1.%2.%3")
                    .arg(new_day, 2, 10, QChar('0'))
                    .arg(new_month, 2, 10, QChar('0'))
                    .arg(new_year, 4, 10, QChar('0')));
}

Date Date::previousDay() {
    int new_day = this->day;
    int new_month = this->month;
    int new_year = this->year;

    if (new_year == 0 && new_month == 1 && new_day == 1) {
        return Date(QString("31.12.9999"));
    }

    if (new_day == 1 && new_month == 1) {
        new_year--;
        new_month = 12;
        new_day = 31;
    } else if (new_day == 1) {
        new_month--;
        new_day = daysInMonth(new_month, new_year);
    } else {
        new_day--;
    }

    return Date(QString("%1.%2.%3")
                    .arg(new_day, 2, 10, QChar('0'))
                    .arg(new_month, 2, 10, QChar('0'))
                    .arg(new_year, 4, 10, QChar('0')));
}

short Date::weekNumber() {
    return dayOfYear() / 7 + 1;
}

short Date::dayOfWeek()
{
    int YY = this->year % 100;
    int year_code = (YY + (YY / 4)) % 7;
    QMap<int, int> month_codes = {{1,  0},{2,  3},{3,  3},{4,  6},{5,  1},{6,  4},{7,  6},{8,  2},{9,  5},{10, 0},{11, 3},{12, 5}};

    int month_code = month_codes.value(this->month);

    int century_code = ((this->year / 100) % 20 - 3) * (-2);
    int date_number = this->day;
    int leap_year_code = (isLeapYear(this->year) && (month == 1 || month == 2));
    int result = qAbs(year_code + month_code + century_code + date_number - leap_year_code);
    return result % 7;
}

short Date::dayOfYear()
{
    int count = this->day;
    for (int i = 1; i < this->month; i++) {
        count += daysInMonth(i, this->year);
    }
    return count;
}

int Date::daysTillYourBithday(Date bithdaydate)
{
    Date nextBithday(bithdaydate.day_string);

    if (nextBithday.getYear() > this->year) {
        return this->duration(bithdaydate);
    }
    else if (nextBithday.getYear() == this->year) {
        return this->duration(Date(QString("%1.%2.%3")
                                       .arg(nextBithday.day, 2, 10, QChar('0'))
                                       .arg(nextBithday.month, 2, 10, QChar('0'))
                                       .arg(this->year + 1, 4, 10, QChar('0'))));
    }
    else if (this->duration(nextBithday, true) < 0) {
        return this->duration(Date(QString("%1.%2.%3")
                                       .arg(this->day, 2, 10, QChar('0'))
                                       .arg(this->month, 2, 10, QChar('0'))
                                       .arg(this->year + 1, 4, 10, QChar('0'))));
    }
    else {
        return this->duration(nextBithday.day_string);
    }
}

int Date::duration(Date date, bool sign)
{
    int start_year = fmin(this->year, date.getYear());
    int days1 = this->dayOfYear(), days2 = date.dayOfYear();
    for (int i = start_year; i < this->year; i++) {
        days1 += (this->isLeapYear(i)?366:365);
    }

    for (int i = start_year; i < date.getYear(); i++) {
        days2 += (date.isLeapYear(i)?366:365);
    }
    return (sign?days2-days1:abs(days2-days1));
}

int Date::getDay()
{
    return this->day;
}

int Date::getYear()
{
    return this->year;
}

int Date::getMonth()
{
    return this->month;
}
