#include <stdio.h>
#include <string.h>

int n, a;
int dp[2][2];

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            dp[i & 1][0] = max(dp[~i & 1][1], dp[~i & 1][0]);
            dp[i & 1][1] = dp[~i & 1][0] + a;
        }
        printf("%d\n", max(dp[~n & 1][0], dp[~n & 1][1]));
    }
    return 0;
}