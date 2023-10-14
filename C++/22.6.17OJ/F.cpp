#include <iostream>
using namespace std;

class CDate
{
protected:
	int year, month, day;
public:
	CDate() = default;
	CDate(int year_, int month_, int day_);
};
CDate::CDate(int year_, int month_, int day_)
{
	year = year_; month = month_; day = day_;
}

class CTime
{
protected:
	int hour, minute, second;
public:
    CTime() = default;
    CTime(int hour_, int minute_, int second_);
};
CTime::CTime(int hour_, int minute_, int second_)
{
    hour = hour_; minute = minute_; second = second_;
}

class CWork :public CDate, public CTime
{
private:
	int id;
public:
    CWork() = default;
    CWork(int year, int month, int day, int hour, int minute, int second, int id_):
    CDate(year, month, day), CTime(hour, minute, second)
    {
        id = id_;
    }
	friend bool before(const CWork& w1, const CWork& w2);
};
bool before(const CWork& w1, const CWork& w2)
{

}

int main()
{
	int id, year, month, day, hour, minute, second;
	cin >> id;
	CWork cw();
	while (1)
	{
		if (id != 0)
		{
			cin >> year >> month >> day >> hour >> minute >> second;
		}
		else
		{
			break;
		}
	}

	return 0;
}