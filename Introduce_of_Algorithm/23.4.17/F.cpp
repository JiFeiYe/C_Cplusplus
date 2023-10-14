#include <iostream>
#include <math.h>
using namespace std;

const int MOD = 1e9 + 7;
int a[1010];
int temp[1010];

int max(int a, int b)
{
    return a > b ? a : b;
}

// 默认升序,返回下标
int search(int left, int right, int num)
{
    int ans = -1;
    while (left < right)
    {
        int mid = left + right >> 1;
        if (num > temp[mid])
            left = mid + 1;
        else if (num < temp[mid])
            right = mid;
        else
            return mid;
        ans = left;
    }
    return ans;
}

int main()
{
    int n = 0, b = 0;
    while (scanf("%d%d", &n, &b) != EOF)
    {
        a[1] = b; // 下标从1开始
        for (int i = 2; i <= n; i++)
        {
            a[i] = 1LL * (a[i - 1] + 1) * (a[i - 1] + 1) % MOD;
        }
        int index = 1; // 指向答案序列的末尾
        for (int k = 1; k <= n; k++)
        {
            int ans = search(1, index, a[k]);
            if (ans == -1 || ans == index) // -1表示leftright有误，k表示没找到
                temp[index++] = a[k];
            else
                temp[ans] = a[k];
        }
        printf("%d\n", index - 1);
    }
    return 0;
}