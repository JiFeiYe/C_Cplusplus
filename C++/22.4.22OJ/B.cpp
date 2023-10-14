#include<iostream>
#include<cstring>
using namespace std;

class CVector
{
private:
    int* data;
    int n;
public:
    CVector();
    CVector(int* data_, int n_);
    CVector(const CVector& v);
    void print();
    ~CVector();
    friend CVector add(const  CVector v1, const CVector v2);
};
CVector::CVector()
{
    n = 5;
    data = new int[5];
    int temp = 0;
    for(int i = 0; i < 5; i++)
    {
        data[i] = temp++;
    }
}
CVector::CVector(int* data_, int n_)
{
    n = n_;
    data = new int [n];
    for(int i = 0; i < n; i++)
    {
        data[i] = data_[i];
    }
}
CVector::CVector(const CVector& v)
{
    n = v.n;
    data = new int[n];
    for(int i = 0; i < n; i++)
    {
        data[i] = v.data[i];
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
    delete[] data;
}
CVector add(const  CVector v1, const CVector v2)
{
    for(int i = 0; i < v1.n; i ++)
    {
        v2.data[i] = v1.data[i] + v2.data[i];
    }
    return v2;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int* data1 = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> data1[i];
        }
        CVector cv1(data1, n);
        int* data2 = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> data2[i];
        }
        CVector cv2(data2, n);
        cv1.print(); cv2.print();
        add(cv1, cv2).print();
    }
    return 0;
}