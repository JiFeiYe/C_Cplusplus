#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

template <class T>
class CMatrix
{
private:
    T** arr;//m行，n列
    T** temparr;//n行，m列
    int m, n;
public:
    CMatrix();
    CMatrix(int m1, int n1);
    void transport();
    void print();
    ~CMatrix();
};
template <class T>
CMatrix<T>::CMatrix()
{
    m = 0; n = 0;
    arr = NULL;
    temparr = NULL;
}
template <class T>
CMatrix<T>::CMatrix(int m1, int n1)
{   
    m = m1;
    n = n1;
    // 分配m行n列的二维数组空间
    arr = new T* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new T[n];
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    //
    temparr = new T* [n];
    for (int i = 0; i < n; i++)
    {
        temparr[i] = new T[m];
    }
}
template <class T>
void CMatrix<T>::transport()
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temparr[j][i] = arr[i][j];
        }
    }
    return;
}
template <class T>
void CMatrix<T>::print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m-1; j++)
        {
            cout << temparr[i][j] << " ";
        }
        cout << temparr[i][m-1] << endl;
    }
    return;
}
template <class T>
CMatrix<T>::~CMatrix()
{
    for(int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    for(int i = 0; i < n; i++)
    {
        delete[] temparr[i];
    }
    delete[] temparr;
}

int main()
{
    int t = 0;
    cin >> t;
    char type = ' ';
    int m = 0, n = 0;//m行n列
    while(t--)
    {
        cin >> type >> m >> n;
        if(type == 'I')
        {
            CMatrix<int> cm(m, n);
            cm.transport();
            cm.print();
        }
        else if(type == 'D')
        {
            CMatrix<double> cm(m, n);
            cm.transport();
            cm.print();
        }
        else if(type == 'C')
        {
            CMatrix<char> cm(m, n);
            cm.transport();
            cm.print();
        }
    }
    system("pause");
    return 0;
}