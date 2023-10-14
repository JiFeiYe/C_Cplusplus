#include <bits/stdc++.h>
using namespace std;

int ans;
int n, k;

void DFS(int x, int s, int t) // x表示上一个数，s表示还须s-1次递归(k组需递归k-1次)，t表示n-x
{
    if (s == 1)
    {
        ans++;
        return;
    }
    for (int i = x; i*s <= t; i++) // t/s用于避免前面的数取太大(难)
    {
        DFS(i, s-1, t-i);
    }
}

int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        ans = 0;
        DFS(1, k, n);
        printf("%d\n", ans);
    }
    return 0;
}