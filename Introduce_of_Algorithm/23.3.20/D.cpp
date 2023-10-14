#include <iostream>
#include <string.h>
using namespace std;

int dp[210][10];

int main()
{
    int n = 0, k = 0;
    memset(dp, 0, 2100);
    for (int i = 1; i <= 200; i++)
    {
        dp[i][1] = 1;
        // dp[i][i] = 1;
        // for (int j = i; j <= 10; j++)
        // {
        //     dp[i][j] = 1;
        // }
    }
    dp[0][0] = 1;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        // dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1]
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i >= j)
                    dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            }
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}