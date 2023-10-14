#include <bits/stdc++.h>

int n;

int ans(int a)
{
    int sum = a;
    while (a >= 3)
    {
        sum += a / 3;
        a = a % 3 + a / 3;
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    int l = 0, r = n;
    while (l < r - 1)
    {
        int mid = l + r >> 1;
        if (ans(mid) > n)
            r = mid;
        else if (ans(mid) < n)
            l = mid;
        else
        {
            printf("%d", mid);
            break;
        }
    }
    return 0;
}