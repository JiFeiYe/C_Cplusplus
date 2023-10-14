#include <iostream>
#include <cmath>
using namespace std;

class CFraction
{
private:
    int fz, fm;
public:
    CFraction(int fz_val = 1, int fm_val = 1);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();   // 求对象的分子和分母的最大公约数
    void print();
};

CFraction::CFraction(int fz_val, int fm_val)
{
    fz = fz_val; fm = fm_val;
}
CFraction CFraction::add(const CFraction& r)
{
    CFraction temp(fz * r.fm + fm * r.fz, fm * r.fm);
    return temp;
}
CFraction CFraction::sub(const CFraction& r)
{
    CFraction temp(fz * r.fm - fm * r.fz, fm * r.fm);
    return temp;
}
CFraction CFraction::mul(const CFraction& r)
{
    CFraction temp(fz * r.fz, fm * r.fm);
    return temp;
}
CFraction CFraction::div(const CFraction& r)
{
    CFraction temp(fz * r.fm, fm * r.fz);
    return temp;
}
int CFraction::getGCD()
{
    int r = 0, a = 0, b = 0;
    a = abs(fz); b = abs(fm);
    if (a < b)
    {
        a = a ^ b;
        b = b ^ a;
        a = a ^ b;
    }
    while (1)
    {
        r = a % b;
        if (r == 0)
        {
            return b;
        }
        else
        {
            a = b;
            b = r;
        }
    }
}
void CFraction::print()
{
    int gcd = abs(getGCD());
    fz /= gcd;
    fm /= gcd;
    cout << fz << '/' << fm << endl;
}
int main()//先直接算两数之和再约分
{
    int t = 0;
    cin >> t;
    int fz1 = 0, fm1 = 0, fz2 = 0, fm2 = 0;
    while (t--)
    {
        cin >> fz1; cin.get(); cin >> fm1; cin.get(); cin >> fz2; cin.get(); cin >> fm2;
        CFraction q(fz1, fm1); CFraction r(fz2, fm2);
        CFraction temp;
        temp = q.add(r);
        temp.print();
        temp = q.sub(r);
        temp.print(); 
        temp = q.mul(r);
        temp.print(); 
        temp = q.div(r);
        temp.print();
        cout << endl;
    }
    return 0;
}