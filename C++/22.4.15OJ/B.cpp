#include<iostream>
#include<cmath>
using namespace std;

class Point
{
private:
    double x, y;
public:
    Point(double xx, double yy); // 构造函数
    friend double Distance(Point &a, Point &b);
};
Point::Point(double xx, double yy)
{
    x = xx; y = yy;
}
double Distance(Point &a, Point &b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main()
{
    int t = 0;
    cin >> t;
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        Point point1(x1,y1);
        Point piont2(x2,y2);
        cout << int(Distance(point1,piont2)) << endl;
    }
    return 0;
}