// 洛谷B3636 文字工作
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int dp[N]; // dp[i]表示到达i所需操作次数

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        dp[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!(i & 1)) // 判断偶数
                dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
            else // 奇数
                dp[i] = dp[i - 1] + 1;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}