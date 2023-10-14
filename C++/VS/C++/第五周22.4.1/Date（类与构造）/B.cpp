#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void SetDate(int y, int m, int d);
	void print();
	void addOneDay();
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
void Date::SetDate(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::print()
{
	cout << year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day;
}
void Date::addOneDay()
{
	int flag = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		flag = 1;
	}
	int monthS[13] = { 0,31, flag ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (day > monthS[month])
	{
		month++;
		day = 1;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}

int main()
{
	int t = 0;
	cin >> t;
	t = t / 2;
	while (t--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		Date date1(a, b, c);
		cout << "Today is "; date1.print(); cout << endl;
		date1.addOneDay();
		cout << "Tomorrow is "; date1.print(); cout << endl;
		cin >> a >> b >> c;
		date1.SetDate(a, b, c);
		cout << "Today is "; date1.print(); cout << endl;
		date1.addOneDay();
		cout << "Tomorrow is "; date1.print(); cout << endl;
	}
	return 0;
}