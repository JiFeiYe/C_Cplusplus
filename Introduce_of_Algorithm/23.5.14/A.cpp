#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", (n * (n + 1) / 2) + 1); // 1+1+2+3+4+5+...
    }
    return 0;
}