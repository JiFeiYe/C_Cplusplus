#include<iostream>
using namespace std;

class CVector
{
private:
    int* data;
    int n;
    static int sum;
public:
    CVector();
    CVector(int* data_, int n_);
    void print();
    static void printsum();
    ~CVector();
};
int CVector::sum = 0;
CVector::CVector()
{
    n = 5;
    data = new int[5];
    int temp = 0;
    for(int i = 0; i < 5; i++)
    {
        data[i] = temp++;
    }
    sum = 10;
}
CVector::CVector(int* data_, int n_)
{
    n = n_;
    data = new int [n];
    for(int i = 0; i < n; i++)
    {
        data[i] = data_[i];
        sum += data[i];
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
void CVector::printsum()
{
    cout << sum << endl;
    sum = 0;
}
CVector::~CVector()
{
    delete[] data;
}

int main()
{
    int t = 0;
    cin >> t;
    int m = 0, n = 0;
    while(t--)
    {
        cin >> m;
        while(m--)
        {
            cin >> n;
            int* data = new int[n];
            for(int i = 0; i < n; i++)
            {
                cin >> data[i];
            }
            CVector cv1(data, n);
            cv1.print();
            delete[] data;
        }
        CVector::printsum();
    }
    return 0;
}