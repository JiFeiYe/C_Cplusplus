#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CPoint
{
private:
    int x, y;
public:
    CPoint(int, int);
    void set(int, int);
    int getx();
    int gety();
};
CPoint::CPoint(int x_ = 0, int y_ = 0)
{
    x = x_; y = y_;
}
void CPoint::set(int x_, int y_)
{
    x = x_; y = y_;
}
int CPoint::getx()
{
    return x;
}
int CPoint::gety()
{
    return y;
}

class CRectangle
{
private:
    CPoint leftpoint;
    CPoint rightpoint;
public:
    CRectangle(int leftx, int lefty, int rightx, int righty);
    bool operator>(CPoint& cp_);
    bool operator>(CRectangle& cr);
    bool operator*(CRectangle& cr);
    bool operator==(CRectangle& cr);
    friend ostream& operator<<(ostream& stream, CRectangle& cr);
    operator int();
};
CRectangle::CRectangle(int leftx, int lefty, int rightx, int righty)
{
    leftpoint.set(leftx, lefty);
    rightpoint.set(rightx, righty);
}
bool CRectangle::operator>(CPoint& cp_)
{
    if(cp_.getx() >= leftpoint.getx() && cp_.gety() <= leftpoint.gety())
    {
        if(cp_.getx() <= rightpoint.getx() && cp_.gety() >= rightpoint.gety())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool CRectangle::operator>(CRectangle& cr)
{
    if(leftpoint.getx() <= cr.leftpoint.getx() && leftpoint.gety() >= cr.leftpoint.gety())
    {
        if(rightpoint.getx() >= cr.rightpoint.getx() && rightpoint.gety() <= cr.rightpoint.gety())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool CRectangle::operator*(CRectangle& cr)
{
    int flag = 0;
    for(int i = leftpoint.getx(); i <= rightpoint.getx(); i++)
    {
        for(int j = leftpoint.gety(); j >= rightpoint.gety(); j--)
        {
            if(i >= cr.leftpoint.getx() && i <= cr.rightpoint.getx())
            {
                if(j <= cr.leftpoint.gety() && j >= cr.rightpoint.gety())
                {
                    flag = 1;
                }
            }
        }
    }
    if(flag == 1)
    {
        return true;
    }
    return false;
}
bool CRectangle::operator==(CRectangle& cr)
{
    if(leftpoint.getx() == cr.leftpoint.getx() && leftpoint.gety() == cr.leftpoint.gety())
    {
        if(rightpoint.getx() == cr.rightpoint.getx() && rightpoint.gety() == cr.rightpoint.gety())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else 
    {
        return false;
    }
}
ostream& operator<<(ostream& stream, CRectangle& cr)
{
    stream << cr.leftpoint.getx() << " " << cr.leftpoint.gety() << " " << cr.rightpoint.getx() << " " << cr.rightpoint.gety();
    return stream;
}
CRectangle::operator int()
{
    return (rightpoint.getx() - leftpoint.getx()) * (leftpoint.gety() - rightpoint.gety());
}

int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}