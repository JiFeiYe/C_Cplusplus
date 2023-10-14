#include<iostream>
using namespace std;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
public:
	Complex() = default;
	Complex(double r, double i);
	// 友元函数，复数c1 +- c2(二参数对象相加减)
	friend Complex addCom(const Complex& c1, const Complex& c2);
    friend Complex minusCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c);
};
Complex::Complex(double r, double i)
{
    real = r; imag = i;
}
Complex addCom(const Complex& c1, const Complex& c2)
{
    Complex a1;
    a1.real = c1.real + c2.real;
    a1.imag = c1.imag + c2.imag;
    return a1;
}
Complex minusCom(const Complex& c1, const Complex& c2)
{
    Complex a1;
    a1.real = c1.real - c2.real;
    a1.imag = c1.imag - c2.imag;
    return a1;
}
void outCom(const Complex& c)
{
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}

int main()
{
    double r = 0, i = 0;
    cin >> r >> i;
    Complex c1(r, i);
    int t = 0;
    cin >> t;
    char state = ' ';
    while(t--)
    {
        cin >> state >> r >> i;
        Complex c2(r, i);
        if(state == '+')
        {
            c1 = addCom(c1, c2);
            outCom(c1);
        }
        else if(state == '-')
        {
            c1 = minusCom(c1, c2);
            outCom(c1);
        }
    }
    return 0;
}