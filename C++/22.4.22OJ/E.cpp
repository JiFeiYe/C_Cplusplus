#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class CVector
{
private:
    int* data;
    int n;
public:
    CVector();
    CVector(int n_);
    void print();
    ~CVector();
    friend class CMatrix;
};
CVector::CVector()
{
    n = 0;
    data = new int[100];
    for(int i = 0; i < 100; i++)
    {
        data[i] = 0;
    }
}
CVector::CVector(int n_)
{
    n = n_;
    data = new int [n];
    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
}
void CVector::print()
{
    cout << data[0];
    for(int i = 1; i < n; i++)
    {
        cout  << " " << data[i];
    }
    cout << endl;
}
CVector::~CVector()
{
    //delete[] data;
}

class CMatrix
{
private:
    int** a = NULL;
    int n;
public:
    CMatrix() = default;
    CMatrix(int n);
    CVector multi(const CVector &v1);//计算n阶矩阵与n维向量v1的乘积
    //bool judge(int a, int b);//判定矩阵与向量v1是否可计算乘积
    ~CMatrix();
};
CMatrix::CMatrix(int n_)
{
    n = n_;
    // 先创建n行
    a = new int* [n];
    // 再创建n列
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    // 打印矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}
CVector CMatrix::multi(const CVector &v1)
{
    CVector ret;
    ret.n = v1.n;
    for (int i = 0; i < v1.n; i++)
    {
        for (int j = 0; j < v1.n; j++)
        {
            ret.data[i] += v1 .data[j] * a[i][j];
        }
    }
    return ret;
}
CMatrix::~CMatrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n;
        CMatrix Mat(n);
        cin >> m;
        CVector cv(m);
        if(n != m)
        {
            cout << "error" << endl;
        }
        else
        {
            Mat.multi(cv).print();
        }
    }
    return 0;
}
