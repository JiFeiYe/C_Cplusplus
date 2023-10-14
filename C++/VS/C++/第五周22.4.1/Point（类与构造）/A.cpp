#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point
{
	double x, y;
public:
	Point() = default;
	Point(double x_value, double y_value);
	double getx();
	double gety();
	void setx(double x_value);
	void sety(double y_value);
	double distanceToAnotherPoint(Point p);
};

Point::Point(double x_value, double y_value)
{
	x = x_value; y = y_value;
}
double Point::getx()
{
	return x;
}
double Point::gety()
{
	return y;
}
void Point::setx(double x_value)
{
	x = x_value;
}
void Point::sety(double y_value)
{
	y = y_value;
}
double Point::distanceToAnotherPoint(Point p)
{
	return sqrt(pow(x - p.getx(), 2) + pow(y - p.gety(), 2));
}

int main()
{
	int t = 0;
	cin >> t;
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1,y1), p2(x2,y2);
		double distance = 0;
		distance = p1.distanceToAnotherPoint(p2);
		cout << "Distance of Point(" << fixed << setprecision(2) << p1.getx() << "," << fixed << setprecision(2) << p1.gety() << ") to Point(";
		cout << p2.getx() << "," << p2.gety() << ") is " << fixed << setprecision(2) << distance << endl;
	}
	return 0;
}