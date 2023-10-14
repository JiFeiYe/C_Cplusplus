#include <iostream>
#include <algorithm>
using namespace std;

int a[25];

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int sum = 0;
        int pass = 0;
        for (int i = 0; i < n; i++)
        {
            pass += a[i];
            sum += pass;
        }
        printf("%d\n", sum);
    }
    return 0;
}