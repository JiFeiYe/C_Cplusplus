#include<iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int t = 0;
    cin >> t;
    int a;
    while(t--)
    {
        int left = 0, right = n;
        cin >> a;
        while(left < right -1)
        {
            int mid = left + right >> 1;
            if(arr[mid] <= a) left = mid;
            else right = mid;
        }
        if(arr[left] == a)
            cout << left+1 << endl;
        else
            cout << "error" << endl;
    }
    delete[] arr;
    return 0;
}