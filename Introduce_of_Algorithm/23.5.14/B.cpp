#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e6 + 10;
int a[N] = {-1};

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        // memset(a, -1, N);
        int tempnum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tempnum);
            a[tempnum]++;
        }
        int max = -1, index = 0;
        for (int i = 0; i < N; i++)
        {
            if (max < a[i])
            {
                max = a[i];
                index = i;
            }
        }
        printf("%d\n%d\n", index, max);
    }
    return 0;
}