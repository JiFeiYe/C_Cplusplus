#include <iostream>
#include <algorithm>
using namespace std;

int n, r;
int a[110], b[110];
int flag;

void DFS(int cur)
{
    if(cur == 0) flag = 0;
    if(cur == n)
    {
        if (flag == r)
        {
            for (int i = 1; i <= n; i++)
                if (b[i]) printf("%d ", a[i]);
                printf("\n");
        }
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        flag += i;
        b[n-cur] = i;
        DFS(cur + 1);
        b[n-cur] = 0;
        flag -= i;
    }
}

int main()
{
    while (scanf("%d%d", &n, &r) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        //sort(&a[0], &a[n - 1]);
        DFS(0);
    }
    return 0;
}