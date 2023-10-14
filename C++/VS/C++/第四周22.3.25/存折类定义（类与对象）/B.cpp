#include <iostream>
using namespace std;

class CAcount
{
public:
	long int ID;
	char name[10];
	float balance;

private:

};

void Inbalance(CAcount* count, int j)
{
	int i = 0;
	cin >> i;
	count[j].balance += i;
	cout << "saving ok!" << endl;
	return;
}

void Outbalance(CAcount* count, int j)
{
	int i = 0;
	cin >> i;
	if (count[j].balance >= i)
	{
		count[j].balance -= i;
		cout << "withdraw ok!" << endl;
	}
	else
	{
		cout << "sorry! over limit!" << endl;
	}
	return;
}

int main()
{
	CAcount count[2];
	cin >> count[0].ID >> count[0].name >> count[0].balance;
	cout << count[0].name << "'s balance is " << count[0].balance << endl;
	Inbalance(count,0);
	cout << count[0].name << "'s balance is " << count[0].balance << endl;
	Outbalance(count,0);
	cout << count[0].name << "'s balance is " << count[0].balance << endl;

	cin >> count[1].ID >> count[1].name >> count[1].balance;
	cout << count[1].name << "'s balance is " << count[1].balance << endl;
	Inbalance(count,1);
	cout << count[1].name << "'s balance is " << count[1].balance << endl;
	Outbalance(count,1);
	cout << count[1].name << "'s balance is " << count[1].balance << endl;

	return 0;
}