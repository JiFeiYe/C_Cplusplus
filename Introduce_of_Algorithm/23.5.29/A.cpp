#include <iostream>
#include <algorithm>
using namespace std;

int n;
int record[110];
bool vis[110];
int a[110];

void DFS(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
            printf(" %d" + !i, record[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        record[cur] = a[i];
        DFS(cur + 1);
        vis[i] = false;
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(&a[0], &a[n-1]);
        DFS(0);
    }
    return 0;
}