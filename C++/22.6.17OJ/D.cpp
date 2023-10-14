#include<iostream>
using namespace std;

template <class T>
void tips(T* arr1, T* arr2, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr2[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr1[i];
    }
    cout << endl;
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    char ch = ' ';
    int n = 0;
    while(t--)
    {
        cin >> ch;
        if(ch == 'I')
        {
            cin >> n;
            int* arr1 = new int[n];
            int* arr2 = new int[n];
            for(int i = 0; i < n; i++)
            {
                cin >> arr1[i];
            }
            for(int i = 0; i < n; i++)
            {
                cin >> arr2[i];
            }
            tips(arr1, arr2, n);
        }
        if(ch == 'D')
        {
            cin >> n;
            double* arr1 = new double[n];
            double* arr2 = new double[n];
            for(int i = 0; i < n; i++)
            {
                cin >> arr1[i];
            }
            for(int i = 0; i < n; i++)
            {
                cin >> arr2[i];
            }
            tips(arr1, arr2, n);
        }
        if(ch == 'C')
        {
            cin >> n;
            char* arr1 = new char[n];
            char* arr2 = new char[n];
            for(int i = 0; i < n; i++)
            {
                cin >> arr1[i];
            }
            for(int i = 0; i < n; i++)
            {
                cin >> arr2[i];
            }
            tips(arr1, arr2, n);
        }
    }
}