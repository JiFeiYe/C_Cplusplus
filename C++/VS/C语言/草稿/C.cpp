//#define pi 3.14
//#include<iostream>
//#include<iomanip>
//#include<cstring>
//#include<cmath>
//using namespace std;
//
//class CShape
//{
//public:
//    virtual double area() = 0;
//};
//
//class CCircle :public CShape
//{
//private:
//    double r;
//public:
//    CCircle() = default;
//    void getv(double r_) {
//        r = r_; return;
//    }
//    double area() {
//        return r * r * pi;
//    }
//};
//
//class CSquare :public CShape
//{
//private:
//    double a;
//public:
//    CSquare() = default;
//    void getv(double a_) {
//        a = a_; return;
//    }
//    double area() {
//        return a * a;
//    }
//};
//
//class CRect :public CShape
//{
//private:
//    double a;
//    double b;
//public:
//    CRect() = default;
//    void getv(double a_, double b_) {
//        a = a_; b = b_; return;
//    }
//    double area() {
//        return a * b;
//    }
//};
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    double r = 0, a = 0, b = 0;
//    CCircle circle;
//    CSquare square;
//    CRect rect;
//    CShape* p[3];
//    p[0] = &circle;
//    p[1] = &square;
//    p[2] = &rect;
//    while (t--)
//    {
//        cin >> r;
//        *p[2].getv(a, b);
//    }
//    return 0;
//}