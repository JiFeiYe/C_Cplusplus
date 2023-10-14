#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CTime
{
private:
    int hour;
    int minute;
    int second;
public:
    CTime(int, int, int);
    CTime& operator++();
    CTime operator--(int);
    void print();
};
CTime::CTime(int h = 0, int m = 0, int s = 0)
{
    hour = h; minute = m; second = s;
}
CTime& CTime::operator++()
{
    if(second == 59)
    {
        if(minute == 59)
        {
            if(hour == 11)
            {
                hour = 0; minute = 0; second = 0;
            }
            else
            {
                hour++; minute = 0; second = 0;
            }
        }
        else
        {
            minute++; second = 0;
        }
    }
    else
    {
        second++;
    }
    return *this;
}
CTime CTime::operator--(int)
{
    CTime temp(*this);
    if(second == 0)
    {
        if(minute == 0)
        {
            if(hour == 0)
            {
                hour = 11; minute = 59; second = 59;
            }
            else
            {
                hour--; minute = 59; second = 59;
            }
        }
        else
        {
            minute--; second = 59;
        }
    }
    else
    {
        second--;
    }
    return temp;
}
void CTime::print()
{
    cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
    int hour = 0, minute = 0, second = 0, t = 0;
    cin >> hour >> minute >> second >> t;
    int x = 0;
    CTime ct(hour, minute, second);
    while(t--)
    {
        cin >> x;
        if(x > 0)
        {
            while(x--)
            {
                ++ct;
            }
            ct.print();
        }
        else
        {
            while(x++)
            {
                ct--;
            }
            ct.print();
        }
    }
    return 0;
}