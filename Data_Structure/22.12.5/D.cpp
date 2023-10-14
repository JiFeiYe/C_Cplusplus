#include<iostream>
using namespace std;
const int N = 1e5 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[200];
        for (int i = 0; i < 200; i++)a[i] = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[x + 100]++;
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 199; j >= 0; j--)
            {
                if (a[j] == i)
                {
                    for(int k=0;k<i;k++)cout << j - 100 << ' ';
                }
            }
        }
        cout << endl;
    }
    return 0;
}