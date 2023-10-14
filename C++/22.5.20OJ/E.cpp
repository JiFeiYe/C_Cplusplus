#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

bool isleapyear(int year);
class Student
{
private:
    string name;
    int year;
    int month;
    int day;
public:
    Student() { name = " "; year = 0; month = 0; day = 0; }
    Student(string name_, int year_, int month_, int day_);
    void set(string name_, int year_, int month_, int day_);
    friend int count(Student S);
    friend void compare(int t, Student* S);
};
Student::Student(string name_, int year_, int month_, int day_)
{
    name = name_; year = year_; month = month_; day = day_;
}
void Student::set(string name_, int year_, int month_, int day_)
{
    name = name_; year = year_; month = month_; day = day_;
}

bool isleapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int count(Student S)
{
    int sum = 0;
    int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isleapyear(S.year))
    {
        m[2]++;
    }
    for (int j = 1900; j < S.year; j++)
    {
        sum += 365;
        if (isleapyear(j))
        {
            sum++;
        }
    }
    for (int j = 0; j < S.month; j++)
    {
        sum += m[j];
    }
    sum += S.day;
    return sum;
}
void compare(int t, Student* S)
{
    int temp = 0;
    int* sum = new int[t];
    for (int i = 0; i < t; i++)
    {
        sum[i] = count(S[i]);
    }
    int diff = 10000;//差值
    int temp1 = 0, temp2 = 0;
    for (int i = 0; i < t - 1; i++)
    {
        for (int j = i+1; j < t; j++)
        {
            if (diff >= abs(sum[i] - sum[j]))
            {
                diff = abs(sum[i] - sum[j]);
                temp1 = i; temp2 = j;
            }
        }
    }
    cout << S[temp1].name << "和" << S[temp2].name << "年龄相差最小，为" << diff << "天。";
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    string name = " ";
    int year = 0, month = 0, day = 0;
    Student* S = new Student[t];
    int temp = 0;
    int tempp = t;
    while (t--)
    {
        cin >> name >> year >> month >> day;
        S[temp].set(name, year, month, day);
        temp++;
    }
    compare(tempp, S);
    return 0;
}