#include<iostream>
using namespace std;

int a[10010];

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            int min = 0x3f3f3f, temp = 0, index = 0;
            for (int j = i; j < n; j++)
            {
                if (a[j] < min)
                {
                    min = a[j];
                    index = j;
                }
            }
            temp = a[i];
            a[i] = min;
            a[index] = temp;

            cout << a[0];
            for (int k = 1; k < n; k++)
                cout << " " << a[k];
            cout << endl;
        }
        cout << endl;
    }
}