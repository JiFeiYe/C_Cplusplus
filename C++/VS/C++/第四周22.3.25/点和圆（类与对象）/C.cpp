#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

//-----类定义与实现------
//class Point
//{
//private:
//	double X; double Y;
//public:
//	void getxy(double x, double y)
//	{
//		X = x; Y = y;
//	}
//};
class Point
{
private:
	
public:
	double X; double Y;
};
class Circle
{
private:
	double X; double Y; double R;
public:
	void setCenter(double x, double y)
	{
		X = x; Y = y;
	}
	void setRedius(double r)
	{
		R = r;
	}
	double getArea()
	{
		return 3.14 * R * R;
	}
	double getLength()
	{
		return 2 * 3.14 * R;
	}
	void Contain(Point point)
	{
		double temp = 0;
		temp = sqrt(pow(X - point.X, 2) + pow(Y - point.Y, 2));
		if (temp <= R)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
};



//-----主函数-----
int main()
{
	double x = 0, y = 0, r = 0;//圆心xy半径r
	cin >> x >> y >> r;
	double X = 0, Y = 0;//点XY
	cin >> X >> Y;
	Point point = { X,Y };
	Circle circle;
	circle.setCenter(x, y); circle.setRedius(r);
	cout << fixed << setprecision(2) << circle.getArea() << " " << fixed << setprecision(2) << circle.getLength() << endl;
	circle.Contain(point);
	return 0;
}