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
        for(int i = 1; i < n; i++)//直接插入排序
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(arr[j] > arr[j+1])
                {
                    Swap(arr[j], arr[j+1]);
                }
            }
            Print(n);
        }
        cout << endl;
    }
    return 0;
}