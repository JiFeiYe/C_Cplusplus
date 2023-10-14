#include<iostream>
using namespace std;

int a[10010];
int HalfSearch(int num, int n)
{
    int left = 0, right = n;
    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= num) left = mid;//往右走
        else right = mid;//往左走
    }
    if (a[left] == num)
    {
        return left;
    }
    else if (a[left] > num)
    {
        return left + 1;
    }
    else
    {
        return left - 1;
    }
}
void Swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++)
        {
            int index = HalfSearch(a[i], i);
            for (int j = i; j > index && j > 0; j--)
                Swap(a[j], a[j - 1]);
            cout << a[0];
            for (int k = 1; k < n; k++)
                cout << " " << a[k];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}