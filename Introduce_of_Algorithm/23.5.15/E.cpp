#include <iostream>
#include <algorithm>
using namespace std;

int d[1010];

int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n ; i++)
        {
            scanf("%d", &d[i]);
        }
        sort(d, d+n);
        int pass = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            pass += d[i];
            sum += pass;
            pass += d[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}