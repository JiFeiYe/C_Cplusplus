#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CPoint
{
protected:
    double x; 
    double y;
public:
    CPoint() = default;
    CPoint(double x_, double y_);
};
CPoint::CPoint(double x_, double y_)
{
    x = x_; y = y_;
}

class CCircle:public CPoint
{
protected:
    double r;
public:
    CCircle() = default;
    CCircle(double x_, double y_, double r_):CPoint(x_, y_)
    {
        r = r_;
    }
    double area();
    void print();
};
double CCircle::area()
{
    return 3.14 * r * r;
}
void CCircle::print()
{
    cout << "Circle:(" << x << "," << y << ")," << r << endl;
    cout << "Area:" << area() << endl;
}

class CCylinder:public CCircle
{
protected:
    double h;
public:
    CCylinder() = default;
    CCylinder(double x_, double y_, double r_, double h_):CCircle(x_, y_, r_)
    {
        h = h_;
    }
    double volume();
    void print();
};
double CCylinder::volume()
{
    return area() * h;
}
void CCylinder::print()
{
    cout << "Cylinder:(" << x << "," << y << ")," << r << "," << h << endl;
    cout << "Volume:" << volume() << endl;
}

int main()
{
    double x = 0, y = 0, r = 0, h = 0;
    cin >> x >> y >> r;
    CCircle a(x, y, r);
    a.print();
    cin >> x >> y >> r >> h;
    CCylinder b(x, y, r, h);
    b.print();
    return 0;
}