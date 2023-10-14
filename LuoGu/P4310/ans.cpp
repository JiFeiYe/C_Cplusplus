#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int dp[N]; // dp表示第i个元素结尾的子序列长度

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) // 查看新a[i]值
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++) // 与旧a[j]进行比较
            {
                if ((a[i] & a[j]) != 0) // 注意优先级
                    dp[i] = max(dp[i], dp[j] + 1);
                ans = max(dp[i], ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}