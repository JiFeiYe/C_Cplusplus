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
    void print();
    ~CVector();
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

int main()
{
    int n = 0;
    cin >> n;
    int* data = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    CVector cv1;
    cv1.print();
    CVector cv2(data, n);
    cv2.print();
    delete[] data;
    return 0;
}