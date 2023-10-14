#include<iostream>
using namespace std;

int a[10010];
void QuickSort(int left, int right, int n)
{
    if (left >= right - 1)  return;
    int low = left, high = right - 1, mid = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= mid) high--;
        a[low] = a[high];
        while (low < high && a[low] <= mid) low++;
        a[high] = a[low];
    }
    a[low] = mid;

    cout << a[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;

    QuickSort(left, low, n);
    QuickSort(low + 1, right, n);
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
        QuickSort(0, n, n);
        cout << endl;
    }
    return 0;
}