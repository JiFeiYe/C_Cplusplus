#include<iostream>
#include<iomanip>
using namespace std;

class Time;
class Date
{
private:
    int year, month, day;
public:
    Date() = default;
    Date(int y, int m, int d);
    friend void display(const Date& date, const Time& time);
};
Date::Date(int y, int m, int d)
{
    year = y; month = m; day = d;
}

class Time
{
private:
    int hour, minute, second;
public:
    Time() = default;
    Time(int h, int m, int s);
    friend void display(const Date& date, const Time& time);
};
Time::Time(int h, int m, int s)
{
    hour = h; minute = m; second = s;
}

void display(const Date& date, const Time& time)
{
    cout << date.year << "-" << setfill('0') << setw(2) << date.month << "-" << setfill('0') << setw(2) << date.day << " ";
    cout << setfill('0') << setw(2) << time.hour << ":" << setfill('0') << setw(2) << time.minute << ":" << setfill('0') << setw(2) << time.second << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    while(t--)
    {
        cin >> year >> month >> day >> hour >> minute >> second;
        Date date(year, month, day);
        Time time(hour, minute, second);
        display(date,time);
    }
    return 0;
}