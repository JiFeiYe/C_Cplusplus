#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
	double x, y;
public:
	Point() = default;
	Point(double x_value, double Y_value);
	double getX();
	double getY();
	void setXY(double x1, double y1);
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(const Point& p);
	~Point();
};
Point::Point(double x_value, double y_value)
{
	x = x_value; y = y_value;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
void Point::setXY(double x1, double y1)
{
	x = x1; y = y1;
	cout << "Constructor." << endl;
}
void Point::setX(double x_value)
{
	x = x_value;
}
void Point::setY(double y_value)
{
	y = y_value;
}
double Point::getDisTo(const Point& p)
{
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
Point::~Point()
{

	cout << "Distructor." << endl;
}

struct subscript
{
	int sub1, sub2;
};

int main()
{
	int t = 0;
	cin >> t;
	int n = 0;
	while (t--)
	{
		cin >> n;
		Point* a = new Point[n];
		for (int i = 0; i < n; i++)
		{
			double xtemp = 0, ytemp = 0;
			cin >> xtemp >> ytemp;
			a[i].setXY(xtemp, ytemp);
		}
		//遍历数组获得最大值
		double maxdistance = 0; 
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (maxdistance < a[i].getDisTo(a[j]))
				{
					maxdistance = a[i].getDisTo(a[j]);
					
				}
			}
		}
		//比较最大值，用结构记录下标
		subscript b = { 0,0 };
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (maxdistance == a[i].getDisTo(a[j]))
				{
					b.sub1 = i;
					b.sub2 = j;
					goto here;
				}
			}
		}
here:
		cout << "The longeset distance is " << fixed << setprecision(2) << maxdistance << ",between p[" << b.sub1 << "] and p[" << b.sub2 << "]." << endl;
		delete[] a;
	}

	return 0;
}