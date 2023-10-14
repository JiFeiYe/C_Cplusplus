#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main()
{
	struct receipts
	{
		char name[30];
		char terminal[30];
		char Operator[30];
		char card_issuers[30];
		char validity[30];
		char card_number[30];
		char traded[30];
		float costs;
	}a;
	a = { '0' };
	int t = 0;
	cin >> t;
	int n = 0;
	while (t--)
	{
		cin >> a.name >> a.terminal >> a.Operator >> a.card_issuers >> a.validity >> a.card_number >> a.traded >> a.costs;


		cout << "Name: ";
		n = int(strlen(a.name));
		for (int i = 0; i < n; i++)
		{
			cout << a.name[i];
		}
		cout << endl;
		

		cout << "Terminal: ";
		n = int(strlen(a.terminal));
		for (int i = 0; i < n; i++)
		{
			cout << a.terminal[i];
		}
		cout << " operator: ";
		n = int(strlen(a.Operator));
		for (int i = 0; i < n; i++)
		{
			cout << a.Operator[i];
		}
		cout << endl;


		cout << "Card Issuers: ";
		n = int(strlen(a.card_issuers));
		for (int i = 0; i < n; i++)
		{
			cout << a.card_issuers[i];
		}
		cout << " Validity: ";
		n = int(strlen(a.validity));
		for (int i = 0; i < n; i++)
		{
			cout << a.validity[i];
		}
		cout << endl;


		cout << "CardNumber: ";
		n = int(strlen(a.card_number));
		for (int i = 0; i < 4; i++)
		{
			cout << a.card_number[i];
		}
		for (int i = 4; i < n - 4; i++)
		{
			cout << "*";
		}
		for (int i = n - 4; i < n; i++)
		{
			cout << a.card_number[i];
		}
		cout << endl;


		cout << "Traded: ";
		n = int(strlen(a.traded));
		for (int i = 0; i < n; i++)
		{
			cout << a.traded[i];
		}
		cout << endl;


		cout << "Costs: $" << setiosflags(ios::fixed) << setprecision(2) << a.costs << endl;


		cout << endl;
	}
	return 0;
}