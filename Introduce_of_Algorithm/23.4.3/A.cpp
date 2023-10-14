#include <iostream>
using namespace std;

const int N = 5e7 + 100;
int a[N];
const int C = 1e9 + 7;

void Swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int fun(int left, int right, int k)
{
    int L = left, R = right;
    int mid = a[L];
    while (L < (R - 1))
    {
        while (L < (R - 1) && a[R - 1] >= mid)
            R--;
        a[L] = a[R - 1];
        while (L < (R - 1) && a[L] <= mid)
            L++;
        a[R - 1] = a[L];
    }
    a[L] = mid;
    if (k == L)
        return a[L];
    else if (k < L)
        return fun(left, L, k);
    else
        return fun(R, right, k);
}

int main()
{
    int m = 0, n = 0, k = 0;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        a[0] = m;
        k -= 1;
        for (int i = 1; i < n; i++)
            a[i] = 1LL * a[i - 1] * m % C;
        int L = 0, R = n; // 左开右闭
        printf("%d\n", fun(L, R, k));
    }
    return 0;
}
/*
3 2 2
*/