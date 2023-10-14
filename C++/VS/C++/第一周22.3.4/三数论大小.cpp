/*
#include<iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	int a = 0, b = 0, c = 0;
	int* p1 = &a, * p2 = &b, * p3 = &c;

	int temp = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c;
		if (*p1 <= *p2)
		{
			temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
		if (*p1 <= *p3)

		{
			temp = *p1;
			*p1 = *p3;
			*p3 = temp;
		}
		if (*p2 <= *p3)
		{
			temp = *p2;
			*p2 = *p3;
			*p3 = temp;
		}
		cout << *p1 <<' ' << *p2 <<' ' << *p3 << endl;
	}
	return 0;
}
*/