// n皇后(回溯：DFS+剪枝)
#include <iostream>
#include <string.h>
using namespace std;

int n = 0, tot = 0; 
int a[30]; // 第i行的皇后放在第a[i]列
bool b[30], c[30], d[30];
// b数组：b[j]表示第j列
// c数组：c[i-j]表示某一主对角线
// d数组：d[i+j]表示某一副对角线
// true表示冲突，false表示没冲突

void DFS(int i)
{
    int j = 1;
    for (; j <= n; j++)
    {
        if (!b[j] && !c[i - j] && !d[i + j]) // 判断冲突情况
        {
            a[i] = j; // 第i行的皇后放在第j列
            b[j] = true;
            c[i - j] = true;
            d[i + j] = true;
            if (i < n)
                DFS(i + 1);
            else
                tot += 1;
            b[j] = false; // 回溯
            c[i - j] = false;
            d[i + j] = false;
        }
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for(int i = 0 ; i < 30; i++) // 初始化
        {
            a[i] = 0;
            b[i] = false;
            c[i] = false;
            d[i] = false;
        }
        tot = 0;
        DFS(1);
        printf("%d\n", tot);
    }
    return 0;
}