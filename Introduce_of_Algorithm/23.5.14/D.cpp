#include<iostream>
using namespace std;

const int N = 1e5+5;
int d[2] = {0};

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n = 0;
    int a = 0;
    while(scanf("%d", &n) != EOF)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if(a)
            {
                d[0] = d[0] + 1;
                d[1] = d[1] + 1;
            }
            else
            {
                d[1] = d[0];
                d[0] = 0;
            }
            ans = max(ans, max(d[0], d[1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}