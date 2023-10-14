#include<iostream>
using namespace std;

template <class T>
int name(T* a, T name, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(name == a[i])
        {
            return i;
        }
    }
    return 0;
}

template <class T>
void fn(T* a, int n)
{
    int temp[100] = {0};
    for(int i = 0; i < n; i++)
    {
        temp[name<T>(a, a[i], n)]++; 
    }
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        if(temp[index] <= temp[i])
        {
            index = i;
        }
    }
    cout << a[index] << " " << temp[index] << endl;
    return;
}

int main()
{
    int t = 0; char c = ' '; int n = 0;
    cin >> t;
    while(t--)
    {
        cin >> c >> n;
        if(c == 'I')
        {
            int* a = new int[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            fn(a, n);
            delete[]a;
        }
        else if(c == 'C')
        {
            char* a = new char[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            fn(a, n);
            delete[]a;
        }
        else if(c == 'S')
        {
            string* a = new string[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            fn(a, n);
            delete[]a;
        }
    }   
    //system("pause");
    return 0;
}