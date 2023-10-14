#include <iostream>
using namespace std;

int main()
{
    string **p = new string*[13];
    string a1 = "January";
    string a2 = "February";
    string a3 = "March";
    string a4 = "April";
    string a5 = "May";
    string a6 = "June";
    string a7 = "July";
    string a8 = "Aguest";
    string a9 = "September";
    string a10 = "October";
    string a11 = "November";
    string a12 = "December";
    p[1] = &a1; p[2] = &a2; p[3] = &a3; p[4] = &a4; p[5] = &a5; p[6] = &a6;
    p[7] = &a7; p[8] = &a8; p[9] = &a9; p[10] = &a10; p[11] = &a11; p[12] = &a12;
    int t = 0;
    cin >> t;
    int month = 0;
    while(t--)
    {
        cin >> month;
        if(1 <= month && 12 >= month)
        {
            cout << *p[month] << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
    return 0;
}