// 洛谷 P1044 [NOIP2003 普及组] 栈
// https://blog.csdn.net/rhythm_1/article/details/112373391
#include <iostream>
#include <algorithm>
using namespace std;

int dp[20][20]; // i表示栈里的数，j表示队列里的数，dp[i][j]表示情况数

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            dp[i][0] = 1; // 队列中没有数时，仅有一种情况
        dp[0][1] = 1;
        for (int j = 2; j <= n; j++)
        {
            for (int i = j - 1; i >= 1; i--) // 离谱
                // 当前dp[i][j]的操作只能出栈一个数或者进栈一个数
                // 则dp[i][j]的情况由dp[i-1][j]和dp[i+1][j-1]决定
                dp[i][j - i] = dp[i - 1][j - i] + dp[i + 1][j - i - 1];
            // 初始状态仅有进栈一种情况
            dp[0][j] = dp[1][j - 1];
        }
        for (int j = 0; j <= n; j++)
        {
            // 初始状态只能有进栈一个数这一种情况
            dp[0][j] = dp[1][j - 1];
        }
        printf("%d\n", dp[0][n]);
    }
    return 0;
}