// 洛谷B3637 最长上升子序列
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5 * 1e3 + 5;
int a[N];
int dp[N]; // dp表示以第i个数为结尾的最长上升子序列的长度
// dp[k] = max(dp[i] | i < k && a[i] < a[k]) + 1;

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            dp[i] = 1;
        }
        dp[0] = 1;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < k; i++)
                if (a[i] < a[k] && dp[k] < dp[i] + 1 ) // 注意防止dp小值覆盖大值
                    dp[k] = dp[i] + 1; // 条件dp[k] < dp[i] + 1也可以在这一行写为max(dp[k],dp[i]+1)
        int max = -1;
        for (int i = 0; i < n; i++)
            if (max < dp[i])
                max = dp[i];
        printf("%d\n", max);
    }
    return 0;
}