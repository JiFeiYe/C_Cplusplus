#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
void line(T* arr, int k)
{
    //while(1)
    //{
        int index = -1;
        for(int i = k-1; i > 0; i--)
        {
            if(arr[i] > arr[i-1])
            {
                index = i - 1;
                break;
            }
        }
        T temp;
        if(index == -1)
        {
            goto here;
        }
        for(int i = k-1; i > index; i--)
        {
            if(arr[index] < arr[i])
            {
                temp = arr[index];
                arr[index] = arr[i];
                arr[i] = temp;
                break;
            }
        }
        here:
        sort(arr+index+1, arr+k);
    //}
    cout << arr[0];
    for(int i = 1; i < k; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main()
{
    int n = 0; 
    cin >> n;
    char ch = ' ';
    int k = 0;
    while(n--)
    {
        cin >> ch >> k;
        if(ch == 'C')
        {
            char* arr = new char[k];
            for(int i = 0; i < k; i++)
            {
                cin >> arr[i];
            }
            line(arr, k);
        }
        else if(ch == 'I')
        {
            int* arr = new int[k];
            for(int i = 0; i < k; i++)
            {
                cin >> arr[i];
            }
            line(arr, k);
        }
        else if(ch == 'D')
        {
            double* arr = new double[k];
            for(int i = 0; i < k; i++)
            {
                cin >> arr[i];
            }
            line(arr, k);
        }
        else if(ch == 'S')
        {
            string* arr = new string[k];
            for(int i = 0; i < k; i++)
            {
                cin >> arr[i];
            }
            line(arr, k);
        }
    }
    //system("pause");
    return 0;
}