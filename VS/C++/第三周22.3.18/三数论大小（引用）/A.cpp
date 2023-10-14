#include <iostream>
using namespace std;

void Rank(int& a1, int& b1, int& c1, int& t1)
{
	int temp = 0;
	if (a1 < b1)
	{
		temp = b1;
		b1 = a1;
		a1 = temp;
	}
	if (a1 < c1)
	{
		temp = c1;
		c1 = a1;
		a1 = temp;
	}
	if (b1 < c1)
	{
		temp = c1;
		c1 = b1;
		b1 = temp;
	}
	cout << a1 << ' ' << b1 << ' ' << c1 << endl;
	return;
}
int main()
{
	int t = 0;
	cin >> t;
	int a = 0, b = 0, c = 0;
	while (t--)
	{
		cin >> a >> b >> c;
		Rank(a, b, c,t);
	}
	return 0;
}