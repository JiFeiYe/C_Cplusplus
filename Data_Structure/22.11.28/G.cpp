#include<iostream>
using namespace std;

int arr[5050];
int count;
void Init()
{
    count = 0;
    for(int i = 0; i < 5050; i++)
    {
        arr[i] = 0;
    }
    return;
}
void Swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
int main()
{
    int n = 0;
    while(cin >> n)
    {
        Init();
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for(int i = n; i; i--)//冒泡
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[j] < arr[j-1])
                {
                    count++;
                    Swap(arr[j], arr[j-1]);
                }
            }
        }
        // for(int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        cout << count << endl;
    }
    return 0;
}