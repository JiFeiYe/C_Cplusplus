#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

class Complex
{
private:
    float real, image;
public:
    Complex(float, float);
    friend Complex operator+(Complex& C1, Complex& C2);
    friend Complex operator-(Complex& C1, Complex& C2);
    friend Complex operator*(Complex& C1, Complex& C2);
    void show();
};
Complex::Complex(float real_ = 0, float image_ = 0)
{
    real = real_; image = image_;
}
Complex operator+(Complex& C1, Complex& C2)
{
    Complex Ctemp;
    Ctemp.real = C1.real + C2.real;
    Ctemp.image = C1.image + C2.image;
    return Ctemp;
}
Complex operator-(Complex& C1, Complex& C2)
{
    Complex Ctemp;
    Ctemp.real = C1.real - C2.real;
    Ctemp.image = C1.image - C2.image;
    return Ctemp;
}
Complex operator*(Complex& C1, Complex& C2)
{
    Complex Ctemp;
    Ctemp.real = C1.real*C2.real - C1.image*C2.image;
    Ctemp.image = C1.image*C2.real + C1.real*C2.image;
    return Ctemp;
}
void Complex::show()
{
    cout << "Real=" << real << " Image=" << image << endl;
}

int main()
{
    float real1 = 0, image1 = 0, real2 = 0, image2 = 0;
    cin >> real1 >> image1 >> real2 >> image2;
    Complex C1(real1, image1), C2(real2, image2);
    Complex Ctemp;
    Ctemp = C1 + C2;
    Ctemp.show();
    Ctemp = C1 - C2;
    Ctemp.show();
    Ctemp = C1 * C2;
    Ctemp.show();
    return 0;
}