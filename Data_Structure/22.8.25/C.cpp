#include<iostream>
#include<iomanip>
using namespace std;

class Date{
    int year, month, day;
public:
    Date();//缺省构造函数，给year、month、day分别赋值为1900、1、1
    Date(int y, int m, int d);//带参构造函数，给year、month、day分别赋参数的值
    int getYear();//返回当前日期的年份
    int getMonth();//返回当前日期的月份
    int getDay();//返回当前日期的日
    void setDate(int y, int m, int d);//按参数重设日期的值
    void print();//按格式输出当前日期的年、月、日(无回车)
    void addOneDay();//在当前日期上加一天
};
Date::Date()
{
    year = 1900; month = 1; day = 1;
}
Date::Date(int y, int m, int d)
{
    year = y; month = m; day = d;
}
int Date::getYear()
{
    return year;
}
int Date::getMonth()
{
    return month;
}
int Date::getDay()
{
    return day;
}
void Date::setDate(int y, int m, int d)
{
    year = y; month = m; day = d;
}
void Date::print()
{
    cout << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << endl;
}
void Date::addOneDay()
{
    //闰年判断
    int flag = 0;
    if(year%4 == 0 && year%100 != 0 || year%400 == 0)
    {
        flag = 1;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 | month == 8 || month == 10)//十二月重新写
    {
        if(day == 31)
        {
            month++; day = 1;
        }
        else
        {
            day++;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)//二月重新写
    {
        if(day == 30)
        {
            month++; day = 1;
        }
        else
        {
            day++;
        }
    }
    else if(month == 2)
    {
        if(day == 29 || day == 28 && flag == 0)
        {
            month++; day = 1;
        }
        else
        {
            day++;
        }
    }
    else if(month == 12)
    {
        if(day == 31)
        {
            year++; month = 1; day = 1;
        }
        else
        {
            day++;
        }
    }
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    int flip = 0;//翻转
    int year = 0, month = 0, day = 0;
    Date D1;
    while(t--)
    {
        cin >> year >> month >> day;
        if(flip == 0)//构造函数
        {
            Date D1(year, month, day);
            cout << "Today is ";
            D1.print();
            D1.addOneDay();
            cout << "Tomorrow is ";
            D1.print();
            flip = 1;
        }
        else if(flip == 1)//setday方法
        {
            D1.setDate(year, month, day);
            cout << "Today is ";
            D1.print();
            D1.addOneDay();
            cout << "Tomorrow is ";
            D1.print();
            flip = 1;
            flip = 0; 
        }
    }
    return 0;
}