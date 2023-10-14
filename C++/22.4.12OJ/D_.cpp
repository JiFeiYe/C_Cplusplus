#include<iostream>
#include<cstring>
using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate(){};
    CDate(int y, int m, int d);
    CDate(CDate& date_);
    bool isLeapYear();
    int getYear();
    int getMonth();
    int getDay();
    int getDayofYear();
};
CDate::CDate(CDate& date_)
{
    year = date_.year;
    month = date_.month;
    day = date_.day;
}
CDate::CDate(int y, int m, int d)
{
    year = y, month = m, day = d;
}
bool CDate::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int CDate::getYear()
{
    return year;
}
int CDate::getMonth()
{
    return month;
}
int CDate::getDay()
{
    return day;
}
int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear())
    {
        a[2]++;
    }
    // 求日期的天数
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}

class CD
{
private:
    char* name = NULL;
    char type;
    char media;
    CDate date;//截止日期
public:
    CD(char* name_, char type_, char media_,const CDate& date__);//初始化
    CD(const CD& cd_);//拷贝构造
    void testout();//输出
    ~CD();//析构
};
CD::CD(char* name_, char type_, char media_,const CDate& date__)
{
    name = new char[30];
    strcpy(name, name_);
    type = type_;
    media = media_;
    date = date__;
}
CD::CD(const CD& cd_)
{
    name = new char[30];
    strcpy(name, cd_.name);
    type = 'B';
    media = 'H';
    date = cd_.date;
}
void CD::testout()//当日2015.4.7
{
    cout << "name:" << name << endl;
    if(type == 'O')
        cout << "type:original" << endl;
    else if(type == 'B')
        cout << "type:backup" << endl;
    else if(type == 'T')
        cout << "type:trial" << endl;
    if(media == 'D')
        cout << "media:optical disk" << endl;
    else if(media == 'U')
        cout << "media:USB disk" << endl;
    else if(media == 'H')
        cout << "media:hard disk" << endl;
    //----------------------------------------
    int result = 0, temp = 0;
    int months1[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int months2[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(date.getYear() == 0 && date.getMonth() == 0 && date.getDay() == 0)
    {
        cout << "this software has unlimited use" << endl;
    }
    else if(date.getYear() < 2015)
    {
        cout << "this software has expired" << endl;
    }
    else if(date.getYear() == 2015 && date.getMonth() < 4)
    {
        cout << "this software has expired" << endl;
    }
    else if(date.getYear() == 2015 && date.getMonth() == 4 && date.getDay() < 7)
    {
        cout << "this software has expired" << endl;
    }
    else if(date.getYear() == 2015 && date.getMonth() == 4 && date.getDay() == 7){}
    else if(date.getYear() > 2015)//隔年以上
    {
        result = 268;
        int years = date.getYear() - 2015 - 1;//减一防止多算一年
        while(years--)
        {
            if(date.isLeapYear())
            {
                result += 366;
            }
            else
            {
                result += 365;
            }
        }
        if(date.isLeapYear())
        {
            for(int i = 1; i < date.getMonth(); i++)
            {
                result += months1[i];
            }
        }
        else
        {
            for(int i = 1; i < date.getMonth(); i++)
            {
                result += months2[i];
            }
        }
        result += date.getDay();
        cout << "this software is going to be expired in " << result << " days" << endl;
    }
    else//同年
    {
        if(date.getMonth() == 4)
        {
            result = date.getDay() - 7;
        }
        else if(date.getMonth() == 5)
        {
            result = 23 + date.getDay();
        }
        else
        {
            result = 23;
            for(int i = 5; i < date.getMonth(); i++)
            {
                result += months2[i];
            }
            result += date.getDay();
        }
        cout << "this software is going to be expired in " << result << " days" << endl;
    } 
    return;
}
CD::~CD()
{
    delete[] name;
}

int main()
{
    int t = 0;
    cin >> t;
    char name[30] = {" "};
    char type = ' ', media = ' ';
    int year = 0, month = 0, day = 0;
    while(t--)
    {
        cin >> name >> type >> media >> year >> month >> day;
        CDate date(year, month, day);
        CD cd(name, type, media, date);
        CD cd_ = cd;
        cd.testout();
        cout << endl;
        cd_.testout();
        cout << endl;
    }
    return 0;
}