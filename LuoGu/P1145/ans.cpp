#include <bits/stdc++.h>

const int K = 30;
int a[K];

void move(int i, int len)
{
    while (i != len - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    return;
}

int main()
{
    int k = 0;
    while (scanf("%d", &k) != EOF)
    {
        for (int i = 0; i < k; i++)
        {
            a[i] = 1;
            a[i + k] = 0;
        }
        int p = 0;       // 静态指针
        int len = 2 * k; // 数组长度
        int m = k;       // 初始化m
        int count = 0;   // 计数杀死了几个坏人
        while (count != k)
        {
            if (a[(p + m) % len] == 0)
            {
                // move((p + m) % len, len);
                p = (p + m) % len;
                len--;
                count++;
            }
            else
            {
                p = 0;
                len = 2 * k;
                m++;
                count = 0;
                for (int i = 0; i < k; i++)
                {
                    a[i] = 1;
                    a[i + k] = 0;
                }
            }
        }
        printf("%d", m + 1); // 前面均是从0开始，这里输出的m是从1开始，故加1
    }
    return 0;
}
