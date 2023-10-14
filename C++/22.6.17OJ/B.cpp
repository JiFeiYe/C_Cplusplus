#include<iostream>
using namespace std;

int main()
{
    int t = 20021212;
    int day = t % 100;
    int month = t % 10000 / 100;
    int year = t / 10000;
    cout << t << " " <<year << " " << month << " " << day << endl;
    system("pause");
    return 0;
}