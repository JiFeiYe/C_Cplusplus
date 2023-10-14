#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

class MYMatrix
{
private:
    int n;
    int** a;
public:
    MYMatrix(int, int**);
    MYMatrix(const MYMatrix& m);
    MYMatrix operator*(const MYMatrix& m);
    void print();
    ~MYMatrix();
};
MYMatrix::MYMatrix(int n_ = 0, int** a_ = 0)
{
    n = n_;
    a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = a_[i][j];
        }
    }
}
MYMatrix::MYMatrix(const MYMatrix& m)
{
    n = m.n;
    a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = m.a[i][j];
        }
    }
}
MYMatrix MYMatrix::operator*(const MYMatrix& m)
{
    MYMatrix mtemp(n, a);
    for (int i = 0; i < n; i++)//结果行
    {
        for (int j = 0; j < n; j++)//结果列
        {
            for (int k = 0; k < n; k++)
            {
                mtemp.a[i][j] += a[i][k] * m.a[k][j];
            }
        }
    }
    return mtemp;
}
void MYMatrix::print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
            if (j != (n - 1))
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
MYMatrix::~MYMatrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

int main()
{
    int n = 0;
    cin >> n;
    int** a = new int* [n];
    int** b = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }
    MYMatrix m1(n, a), m2(n, b);
    MYMatrix mtemp = m1 * m2;
    mtemp.print();
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;
    return 0;
}