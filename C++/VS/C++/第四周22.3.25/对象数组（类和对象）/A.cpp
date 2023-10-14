#include <iostream>
using namespace std;

class Student
{
private:


public:
	char name[10];
	int ID;
	char sex[21];
	char institute[21];//ѧԺ
	char phone[21];

};

void cinstudent(Student* student, int t)
{
	for (int i = 0; i < t; i++)
	{
		cin >> student[i].name >> student[i].ID >> student[i].sex >> student[i].institute >> student[i].phone;
	}
	return;
}

int main()
{
	Student student[10];
	int t = 0;
	cin >> t;
	cinstudent(student, t);
	for (int i = 0; i < t; i++)
	{
		cout << student[i].name << endl;
	}
	return 0;
}