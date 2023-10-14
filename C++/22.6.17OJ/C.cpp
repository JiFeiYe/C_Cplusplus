#include<iostream>
#include<iomanip>
using namespace std;

class CDate
{
private:
    int year, month, day;
public:
	CDate() = default;
    CDate(int ymd);
    operator int();
	void print();
};
CDate::CDate(int ymd)
{
    day = ymd % 100;
    month = ymd % 10000 / 100;
    year = ymd / 10000;
}
CDate::operator int()
{
    return year*10000 + month*100 + day;
}
void CDate::print()
{
	cout << year << "年" << setfill('0') << setw(2) << month << "月" << setfill('0') << setw(2) << day << "日" << endl;
}

int main()
{
	int t, t1, t2;
	CDate c1, c2;
	cin >> t;
	while (t--)
	{
		cin >> t1 >> t2;
		c1 = t1;
		c2 = t2;
		((c1 > c2) ? c1 : c2).print(); //日期大的输出，在代码c1 > c2中，会自动把c1和c2转换为整数进行比较
	}
	//system("pause");
	return 0;
}