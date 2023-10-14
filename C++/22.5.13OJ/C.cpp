#define pi 3.14
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CShape 
{
public:
    virtual double area() = 0;
};

class CCircle:public CShape
{
private:
    double r;
public:
    CCircle() = default;
    CCircle(double r_){
        r = r_; return;
    }
    double area(){
        return r * r * pi;
    }
};

class CSquare:public CShape
{
private:
    double a;
public:
    CSquare() = default;
    CSquare(double a_){
        a = a_; return;
    }
    double area(){
        return a * a;
    }
};

class CRect:public CShape
{
private:
    double a;
    double b;
public:
    CRect() = default;
    CRect(double a_, double b_){
        a = a_; b = b_; return;
    }
    double area(){
        return a * b;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    double r = 0, a = 0, b = 0;
    CShape* p[3];
    while(t--)
    {
        cin >> r;
        p[0] = new CCircle(r);
        cout << fixed << setprecision(2) << p[0]->area() << endl; 
        cin >> a;
        p[1] = new CSquare(a);
        cout << fixed << setprecision(2) << p[1]->area() << endl;
        cin >> a >> b;
        p[2] = new CRect(a,b);
        cout << fixed << setprecision(2) << p[2]->area() << endl;
    }
    return 0;
}