#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class C2D
{
protected:
    double x; double y;
public:
    C2D() = default;
    C2D(double x_, double y_);
    double getDistance();
};
C2D::C2D(double x_, double y_)
{
    x = x_; y = y_;
}
double C2D::getDistance()
{
    return sqrt(x*x + y*y);
}

class C3D:public C2D
{
protected:
    double z;
public:
    C3D() = default;
    C3D(double x_, double y_, double z_):C2D(x_, y_)
    {
        z = z_;
    }
    double getDistance();
};
double C3D::getDistance()
{
    return sqrt(x*x + y*y + z*z);
}

int main()
{
    double x = 0, y = 0, z = 0;
    cin >> x >> y;
    C2D a(x, y);
    cout << a.getDistance() << endl;
    cin >> x >> y >> z;
    C3D b(x, y, z);
    cout << b.getDistance() << endl;
    cin >> x >> y >> z;
    C3D c(x, y, z);
    cout << c.getDistance() << endl;
    cout << c.C2D::getDistance() << endl;
    return 0;
}