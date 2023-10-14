#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	const char *a[12] = { "January","February" ,"March","April",
					 "May","June","July","Aguest","September",
					 "October","November","December"};
	int test = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> test;
		switch (test)
		{
		case 1:cout << *(a + test - 1) << endl; break;
		case 2:cout << *(a + test - 1) << endl; break;
		case 3:cout << *(a + test - 1) << endl; break;
		case 4:cout << *(a + test - 1) << endl; break;
		case 5:cout << *(a + test - 1) << endl; break;
		case 6:cout << *(a + test - 1) << endl; break;
		case 7:cout << *(a + test - 1) << endl; break;
		case 8:cout << *(a + test - 1) << endl; break;
		case 9:cout << *(a + test - 1) << endl; break;
		case 10:cout << *(a + test - 1) << endl; break;
		case 11:cout << *(a + test - 1) << endl; break;
		case 12:cout << *(a + test - 1) << endl; break;
		default:cout << "error" << endl; break;
		}
	}
	return 0;
}