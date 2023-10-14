#include<iostream>
using namespace std;

int arr[5050];
void Init()
{
    for(int i = 0; i < 5050; i++)
        arr[i] = 0;
}
void Swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
void Print(int n)
{
    cout << arr[0];
    for(int i = 1; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}
void InsertSort(int n, int i, int gap)
{
    for(int j = i+gap; j < n; j += gap)
    {
        for(int k = j-gap; k >= i; k -= gap)
        {
            if(arr[k] < arr[k+gap])
            {
                Swap(arr[k] ,arr[k+gap]);
            }
        }
    }
}
int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    while(t--)
    {
        Init();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for(int gap = n/2; gap >= 1; gap /= 2)
        {
            for(int i = 0; i < gap; i++)
            {
                InsertSort(n, i, gap);
            }
            Print(n);
        }
        cout << endl;
    }
    return 0;
}