#include<iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int t = 0;
    cin >> t;
    int a;
    while(t--)
    {
        int flag = 0;
        cin >> a;
        for(int i = 1; i <= n; i++)
        {
            if(a == arr[i])
            {
                cout << i << endl;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            cout << "error" << endl;
        }
    }
    delete[] arr;
    return 0;
}