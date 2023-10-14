#include<iostream>
#include <algorithm>
using namespace std;

template <class T>
void judge(T* arr)
{
    T temparr[6];
    for(int i = 0; i < 6; i++)
    {
        temparr[i] = arr[i];
    }
    sort(temparr, temparr+6);
    int flag = 0;
    for(int i = 0; i < 6; i++)
    {
        if(temparr[i] != arr[i])
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}

int main()
{
    char ch = ' ';
    while(cin >> ch)
    {
        if(ch == 'c')
        {
            char arr[6] = {' '};
            for(int i = 0; i < 6; i++)
            {
                cin >> arr[i];
            }
            judge(arr);
        }
        else if(ch == 'i')
        {
            int arr[6] = {0};
            for(int i = 0; i < 6; i++)
            {
                cin >> arr[i];
            }
            judge(arr);
        }
        else if(ch == 'f')
        {
            float arr[6] = {0.0};
            for(int i = 0; i < 6; i++)
            {
                cin >> arr[i];
            }
            judge(arr);
        }
    }
    return 0;
}