#include "date.h"
Date::Date(int dayd,int monthd,int yeard ){
    Date::day=dayd;
    Date::month=monthd;
    Date::year=yeard;
}
void Date::create(QString s ){
    QChar a='0';
    day=s[0].digitValue()*10+s[1].digitValue();
    month=s[3].digitValue()*10+s[4].digitValue();
    year=s[6].digitValue()*1000+s[7].digitValue()*100+s[8].digitValue()*10+s[9].digitValue();
    if(Isleap()){
        days[1]+=1;
    }
}

bool Date::Isleap(){
    if(year%400==0 || (year%4==0 && year%100!=0)){
    return true;
    }
    else{
    return false;
    }
}
short Date::WeekNumber(){
    short temp=0;
    for(int i=0;i<month-1;++i){
        temp+=days[i];
    }
    return (temp+day)/7+1;
}


Date Date::PreviousDay(){
    if(day>1){

    return Date(day-1,month,year);
    }
    else {
        if(month>1){
            return Date(days[month-1],month-1,year);
        }
        else if(year>1){
            return Date(31,12,year-1);
        }
        else{
            return Date(0,0,0);
        }
    }
}
Date Date::NextDay(){
    if(day<days[month-1]){
        return Date(day+1,month,year);
    }
    else {
        if(month<12){
            return Date(1,month+1,year);
        }
        else if(year<9999){
            return Date(1,1,year+1);
        }
        else return Date(0,0,0);
    }
}
QString Date::output_string(Date date){
    QString a;
    return QString::number(WeekNumber());
}
QString Date::outp_n(Date date){
    date=PreviousDay();
    QString a="Not definied";
    if(date.month>9 && date.year>999 && date.day>9 ){
    return QString::number(date.day)+"."+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month>9 && date.year>999 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>999 && date.day>9){
    return QString::number(date.day)+".0"+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>999 && date.day<=9){
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month>9 && date.year>99 && date.day>9){
         return QString::number(date.day)+"."+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if(date.month>9 && date.year>99 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>99 && date.day>9){
        return QString::number(date.day)+".0"+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>99 && date.day<=9){
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if (date.month>9 && date.year>9 && date.day>9){
         return QString::number(date.day)+"."+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if (date.month>9 && date.year>9 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if (date.month<=9 && date.year>9 && date.day>9){
        return QString::number(date.day)+".0"+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if (date.month<=9 && date.year>9 && date.day<=9){
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if(date.month>9 && date.day>9){
        return QString::number(date.day)+"."+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else if(date.month>9 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else if(date.year>0 && date.day>9) {
        return QString::number(date.day)+".0"+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else if(date.year>0 && date.day<=9) {
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else {
        return a;
    }
}
QString Date::outp(Date date){
    date=NextDay();
    date=NextDay();
    QString a="Not definied";
    if(date.month>9 && date.year>999 && date.day>9 ){
        return QString::number(date.day)+"."+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month>9 && date.year>999 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>999 && date.day>9){
        return QString::number(date.day)+".0"+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>999 && date.day<=9){
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+"."+QString::number(date.year);
    }
    else if(date.month>9 && date.year>99 && date.day>9){
        return QString::number(date.day)+"."+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if(date.month>9 && date.year>99 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>99 && date.day>9){
        return QString::number(date.day)+".0"+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if(date.month<=9 && date.year>99 && date.day<=9){
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+".0"+QString::number(date.year);
    }
    else if (date.month>9 && date.year>9 && date.day>9){
        return QString::number(date.day)+"."+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if (date.month>9 && date.year>9 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if (date.month<=9 && date.year>9 && date.day>9){
        return QString::number(date.day)+".0"+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if (date.month<=9 && date.year>9 && date.day<=9){
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+".00"+QString::number(date.year);
    }
    else if(date.month>9 && date.day>9){
        return QString::number(date.day)+"."+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else if(date.month>9 && date.day<=9){
        return "0"+QString::number(date.day)+"."+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else if(date.year>1 && date.day>9) {
        return QString::number(date.day)+".0"+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else if(date.year>0 && date.day<=9) {
        return "0"+QString::number(date.day)+".0"+QString::number(date.month)+".000"+QString::number(date.year);
    }
    else {
        return a;
    }
}

QString Date::output(){
    if(Isleap()){
        return "Yes";
    }
    else return "No";
}
int Date::DateTillYourBirthday(Date birthday){

    int temp=0,temp1=0;
    QDate date_curr=QDate::currentDate();
    for(int i=0;i<birthday.month-1;++i){
        temp+=days[i];
    }
    temp+=birthday.day;
    for(int i=0;i<date_curr.month()-1;++i){
        temp1+=days[i];
    }
    temp1+=date_curr.day();
    if(temp>temp1) return temp-temp1;
    else {
        return 365-temp1;
    }
}

int Date::Duration(Date date){
    QDate datel=QDate::currentDate();
    long long temp1=0,temp2=0;
    for(int i=0;i<datel.month()-1;++i){
        temp1+=days[i];
    }
    temp1+=day;
    temp1+=((year)*365+year/4);
    for(int i=0;i<datel.month()-1;++i){
        temp2+=days[i];
    }
    temp2+=datel.day();
    temp2+=(((datel.year()))*365+datel.year()/4);
    return std::abs(temp1-temp2);
}
QString Date::output_string_1(Date date){
    QString a;
    return QString::number(Duration(date));
}




















