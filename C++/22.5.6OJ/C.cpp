#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class count
{
protected:
    int value;
public:
    int increment();
};

class circount:public count
{
private:
    int minValue, maxVlaue;
public:
    int increment();
};

class clockk:public circount
{
private:
    int h, m, s;
public:
    clockk(int h_, int m_, int s_)
    {
        h = h_; m = m_; s = s_;
    }
    void timee(int ss_);
};
void clockk::timee(int ss_)
{
    int temp = 0;
    s += ss_;
    if(s >= 60)
    {
        temp = s / 60;
        s = s % 60;
        m += temp;
        if(m >= 60)
        {
            temp = m / 60;
            m = m % 60;
            h += temp;
            if(h >= 24)
            {
                h = h % 24;
            }
        }
    }
    cout << h << ":" << m << ":" << s << endl;
    return;
}

int main()
{
    int n = 0;
    cin >> n;
    int h = 0, m = 0, s = 0, ss = 0;
    while(n--)
    {
        cin >> h >> m >> s >> ss;
        clockk a(h, m, s);
        a.timee(ss);
    }
    return 0;
}