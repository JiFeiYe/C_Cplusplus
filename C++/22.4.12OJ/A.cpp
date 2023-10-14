#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Equation
{
private:
	double a, b, c;
public:
	Equation();
	Equation(double a_, double b_, double c_);
	void set(double a_, double b_, double c_);
	void GetRoot();
};
Equation::Equation()
{
	a = 1.0; b = 1.0; c = 0;
}
Equation::Equation(double a_, double b_, double c_)
{
	a = a_; b = b_; c = c_;
}
void Equation::set(double a_, double b_, double c_)
{
	a = a_; b = b_; c = c_;
}
void Equation::GetRoot()
{
	double Delta = pow(b, 2) - 4 * a * c;
	double x1 = 0, x2 = 0;
	double x1_ = 0, x2_ = 0;
	if (Delta == 0)
	{
		x1 = (-1) * b / (2 * a);
		cout << "x1=x2=" << fixed << setprecision(2) << x1 << endl;
	}
	else if (Delta > 0)
	{
		x1 = ((-1) * b + sqrt(Delta)) / (2 * a);
		x2 = ((-1) * b - sqrt(Delta)) / (2 * a);
		cout << "x1=" << fixed << setprecision(2) << x1 << " x2=" << fixed << setprecision(2) << x2 << endl;
	}
	else//虚数
	{
		x1 = ((-1) * b) / (2 * a);
		x1_ = (sqrt((-1) * Delta)) / (2 * a);
		x2 = ((-1) * b) / (2 * a);
		x2_ = ((-1) * sqrt((-1) * Delta) / (2 * a));
		cout << "x1=" << fixed << setprecision(2) << x1;
		if (x1_ > 0)
		{
			cout << "+" << fixed << setprecision(2) << x1_ << "i x2=" << fixed << setprecision(2) << x2;
		}
		else
		{
			cout << fixed << setprecision(2) << x1_ << "i x2=" << fixed << setprecision(2) << x2;
		}
		if (x2_ > 0)
		{
			cout << "+" << fixed << setprecision(2) << x2_ << "i" << endl;
		}
		else
		{
			cout << fixed << setprecision(2) << x2_ << "i" << endl;
		}
	}
}

int main()
{
	int t = 0;
	cin >> t;
	double a = 0, b = 0, c = 0, Delta = 0;
	Equation root;
	double* x = new double[4];
	while (t--)
	{
		cin >> a >> b >> c;
		root.set(a, b, c);
		root.GetRoot();
	}
	return 0;
}