#include <iostream>
using namespace std;

int res[40][40];
void Circle(int n)
{
    if (n == 1)
    {
        res[0][0] = 1;
        return;
    }
    Circle(n / 2);
    int hn = n / 2;
    for (int i = 0; i < hn; i++)
        for (int j = 0; j < hn; j++)
        {
            res[i + hn][j] = res[i][j] + hn;
            res[i][j + hn] = res[i + hn][j];
            res[i + hn][j + hn] = res[i][j];
        }
}
int main()
{
    Circle(32);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                printf(" %d" + (j == 1), res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}