#include <bits/stdc++.h>
using namespace std;

const int p = 1e6 + 7;
const int N = 105;
const int M = 105;
int a[N];
int dp[N][M]; //dp[i][j]表示种了第i种花后摆了j盆的方案数

int main()
{
    int n = 0, m = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            dp[i][0] = 1;
        }
        
    }
    return 0;
}
