#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

class Vector
{
private:
    int vec[5];
public:
    Vector(int* v);
    Vector() = default;
    Vector(const Vector& obj);
    Vector operator +(const Vector& obj);
    Vector operator -(const Vector& obj);
    void print();
};
Vector::Vector(int* v)
{
    for(int i = 0; i < 5; i++)
    {
        vec[i] = v[i];
    }
}
Vector::Vector(const Vector& obj)
{
    for(int i = 0; i < 5; i++)
    {
        vec[i] = obj.vec[i];
    }
}
Vector Vector::operator +(const Vector& obj)
{
    Vector vtemp;
    for(int i = 0; i < 5; i++)
    {
        vtemp.vec[i] = vec[i] + obj.vec[i];
    }
    return vtemp;
}
Vector Vector::operator -(const Vector& obj)
{
    Vector vtemp;
    for(int i = 0; i < 5; i++)
    {
        vtemp.vec[i] = vec[i] - obj.vec[i];
    }
    return vtemp;
}
void Vector::print()
{
    for(int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[5] = {0};
    int b[5] = {0};
    for(int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < 5; i++)
    {
        cin >> b[i];
    }
    Vector v1(a), v2(b);
    Vector vtemp;
    vtemp = v1 + v2;
    vtemp.print();
    vtemp = v1 - v2;
    vtemp.print();
    return 0;
}