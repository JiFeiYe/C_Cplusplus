#include<iostream>
#include <algorithm>
using namespace std;

template <class T>
void fn(T* a, int n, int beg, int end)
{
    if(beg >= end)
    {
        cout << "[" << a[0];
        for(int i = 1; i < n; i++)
        {
            cout << ", " << a[i];
        }
        cout << "]" << endl;
    }
    else
    {
        if(beg < 0)
        {
            beg = 0;
        }
        if(end >= n)
        {
            end = n;
        }
        sort(a+beg, a+end);
        cout << "[" << a[0];
        for(int i = 1; i < n; i++)
        {
            cout << ", " << a[i];
        }
        cout << "]" << endl;
    }
}

int main()
{
    int t = 0;
    cin >> t;
    string type = " ";
    int n = 0;
    char temp1 = ' ';
    int num1 = 0, num2 = 0;
    while(t--)
    {
        cin >> type >> n >> temp1 >> num1 >> temp1 >> num2 >> temp1 >> temp1;
        if(type == "int")
        {
            int* a = new int[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            fn(a, n, num1, num2);
            delete[] a;
        }
        if(type == "string")
        {
            string* a = new string[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            fn(a, n, num1, num2);
            delete[] a;
        }
        if(type == "float")
        {
            float* a = new float[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            fn(a, n, num1, num2);
            delete[] a;
        }
    }
    system("pause");
    return 0;
}