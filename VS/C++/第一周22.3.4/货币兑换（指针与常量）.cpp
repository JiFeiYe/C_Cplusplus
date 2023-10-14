/*
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	double d = 6.2619, e = 6.6744, y = 0.0516, h = 0.8065;
	const double* p = NULL;//≥£¡ø÷∏’Î
	char a = ' ';
	double money = 0, rmb = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> money;
		if (a == 'D')
		{
			p = &d;
			rmb = money * (*p);
		}
		else if (a == 'E')
		{
			p = &e;
			rmb = money * (*p);
		}
		else if (a == 'Y')
		{
			p = &y;
			rmb = money * (*p);
		}
		else if (a == 'H')
		{
			p = &h;
			rmb = money * (*p);
		}
		cout << fixed << setprecision(4) << rmb << endl;
	}
	return 0;
}
*/