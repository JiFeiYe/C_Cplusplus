#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int su[256];

int sum(int i, int j, int n)
{
    if (i + j < n)
        return su[i + j] - su[i - 1];
    else
        return (su[n] - su[i - 1]) + (su[j - (n - i)]);
}

void DeMaxMin(int *a, int n, int **m, int **s, int flag)
{
    for (int i = 1; i <= n; i++)
        m[i][0] = 0; // 只有一堆石子
    for (int j = 1; j <= n - 1; j++)
        for (int i = 1; i <= n; i++)
        { // i,j互换位置，按照j=0,j=1的顺序对矩阵进行填值
            int k = j - 1;
            m[i][j] = m[i][k] + m[(i + k) % n + 1][0] + sum(i, j, n); // 合并从第i堆开始的往下j堆石子，共计j+1堆
            s[i][j] = k;
            for (k = j - 2; k >= 0; k--)
            {
                int t = m[i][k] + m[(i + k) % n + 1][j - k - 1] + sum(i, j, n);
                if (flag == 0)
                {
                    if (t < m[i][j]) // min
                    {
                        m[i][j] = t;
                        s[i][j] = k;
                    }
                }
                else if (flag == 1)
                {
                    if (t > m[i][j]) // max
                    {
                        m[i][j] = t;
                        s[i][j] = k;
                    }
                }
            }
        }
    return;
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int stone[n + 1];
        stone[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &stone[i]);

        int **SN = new int *[n + 1]();
        int **TN = new int *[n + 1]();
        for (int i = 0; i <= n; i++)
        {
            SN[i] = new int[n + 1];
            TN[i] = new int[n + 1];
        }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
            {
                SN[i][j] = 0;
                TN[i][j] = 0;
            }
        su[0] = 0;
        for (int i = 1; i <= n; i++)
            su[i] = su[i - 1] + stone[i];

        DeMaxMin(stone, n, SN, TN, 0);
        int Min = SN[1][n - 1], posimin = 1;
        for (int i = 2; i <= n; i++)
        {
            if (Min > SN[i][n - 1])
            {
                Min = SN[i][n - 1];
                posimin = i;
            }
        }
        printf("%d\n", Min);

        DeMaxMin(stone, n, SN, TN, 1);
        int Max = SN[1][n - 1], posimax = 1;
        for (int i = 2; i <= n; i++)
        {
            if (Max < SN[i][n - 1])
            {
                Max = SN[i][n - 1];
                posimax = i;
            }
        }
        printf("%d\n", Max);
    }
    return 0;
}