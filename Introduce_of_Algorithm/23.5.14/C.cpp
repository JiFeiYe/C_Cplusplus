#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
double a[N];

int main()
{
    int n = 0, k = 0;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a[i]);
        }
        sort(&a[0], &a[n]);
        for (int i = 0; i < k; i++)
        {
            a[n - 1] = a[n - 1] / 2;
            a[n] = a[n - 1];
            n += 1;
            sort(&a[0], &a[n]);
        }
        cout << int(a[n-1]) << endl;
    }
    return 0;
}