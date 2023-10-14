#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

class Fraction
{
private:
    int fz, fm;
    int commonDivisor(); // 计算最大公约数
    void contracted(); // 分数化简
public:
    Fraction(int , int);
    Fraction(Fraction& F);
    Fraction operator+(Fraction F);
    Fraction operator-(Fraction F);
    Fraction operator*(Fraction F);
    Fraction operator/(Fraction F);
    void set(int = 0, int = 1);
    void disply();
};
Fraction::Fraction(int fz_ = 0, int fm_= 1)
{
    fz = fz_; fm = fm_;
}
Fraction::Fraction(Fraction& F)
{
    fz = F.fz; fm = F.fm;
}
Fraction Fraction::operator+(Fraction F)
{
    Fraction ftemp;
    ftemp.fm = fm*F.fm;
    ftemp.fz = fz*F.fm + fm*F.fz;
    return ftemp;
}
Fraction Fraction::operator-(Fraction F)
{
    Fraction ftemp;
    ftemp.fm = fm*F.fm;
    ftemp.fz = fz*F.fm - fm*F.fz;
    return ftemp;
}
Fraction Fraction::operator*(Fraction F)
{
    Fraction ftemp;
    ftemp.fm = fm*F.fm;
    ftemp.fz = fz*F.fz;
    return ftemp;
}
Fraction Fraction::operator/(Fraction F)
{
    Fraction ftemp;
    ftemp.fm = fm*F.fz;
    ftemp.fz = fz*F.fm;
    return ftemp;
}
void Fraction::set(int fz_, int fm_)
{
    fz = fz_; fm = fm_;
}
void Fraction::disply()
{
    cout << "fraction=" << fz << "/" << fm << endl;
}

int main()
{
    int fz1 = 0, fm1 = 0, fz2 = 0, fm2 = 0;
    cin >> fz1 >> fm1 >> fz2 >> fm2;
    Fraction f1, f2;
    f1.set(fz1, fm1);
    f2.set(fz2, fm2);
    Fraction ftemp;
    ftemp = f1 + f2;
    ftemp.disply();
    ftemp = f1 - f2;
    ftemp.disply();
    ftemp = f1 * f2;
    ftemp.disply();
    ftemp = f1 / f2;
    ftemp.disply();
    return 0;
}