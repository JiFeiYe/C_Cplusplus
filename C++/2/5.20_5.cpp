#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    string name;
    int year;
    int month;
    int day;
public:
    void set(string n, int y, int m, int d);
    int calculate();
    Student();
    friend int operator-(Student&, Student&);
    string get_name();
    int get_year();
    int get_month();
    int get_day();
    int compare(Student&);
};

string Student::get_name()
{
    return name;
}

int Student::get_year()
{
    return year;
}

int Student::get_month()
{
    return month;
}

int Student::get_day()
{
    return day;
}
Student::Student()
{

}

void Student::set(string n, int y, int m, int d)
{
    name = n;
    year = y;
    month = m;
    day = d;
}

int Student::calculate()
{
    int result = 0;
    result = year * 10000 + month * 100 + day;
    return result;
}

int leap(int y)//如果是闰年返回1，如果不是返回0
{
    int x;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0))
        x = 1;
    else
        x = 0;
    return x;
}

int count(Student &S)
{
    int sum = 0;
    int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (leap(S.get_year()))
    {
        m[2]++;
    }
    for (int j = 1900; j < S.get_year(); j++)
    {
        sum += 365;
        if (leap(j))
        {
            sum++;
        }
    }
    for (int j = 0; j < S.get_month(); j++)
    {
        sum += m[j];
    }
    sum += S.get_day();
    return sum;
}

int operator-(Student& s1, Student& s2)
{
    int count_day = 0;
    count_day = count(s1)-count(s2);
    return count_day;
}

int main()
{
    int t;
    cin >> t;
    Student* s = new Student[t];
    for (int i = 0; i < t; i++)
    {
        string n;
        int y, m, d;
        cin >> n >> y >> m >> d;
        s[i].set(n, y, m, d);
    }
    int min_index1 = 0;
    int min_index2 = 0;
    int min = 1000000;
    for (int i = 0; i < t-1; i++)
    {
        int compared = 0;
        int* sum = new int[t];
        for (int i = 0; i < t; i++)
        {
            sum[i] = abs(count(s[i]));
        }
        for (int i = 0; i < t - 1; i++)
        {
            for (int j = i + 1; j < t; j++)
            {
                if (abs(sum[i]-sum[j]) < min)
                {
                    min = compared;
                    min_index2 = i;
                    min_index1 = j;
                }
            }
        }
        delete[]sum;
    }
    int days = abs(s[min_index1] - (s[min_index2]));
    cout << s[min_index1].get_name() << "和" << s[min_index2].get_name() << "年龄相差最小，为" << days << "天。" << endl;
    system("pause");
    return 0;
}