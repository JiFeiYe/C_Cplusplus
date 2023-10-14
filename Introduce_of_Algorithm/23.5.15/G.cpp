#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, record[7] = {0}, mo[7] = {100, 50, 20, 10, 5, 2, 1};

int CalSum(int n, int record[])
{
    // TODO: 计算需要张数，并将各钱所需张数存入record
    for (int i = 0; i < 7; i++)
    {
        record[i] = 0;
    }
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        if (n < mo[i])
            continue;
        record[i] = n / mo[i];
        sum += record[i];
        n = n % mo[i];
    }
    return sum;
}
void PrintFormation(int record[])
{
    // TODO: 基于计算的各钱张数输出式子
    int i = 0;
    for (; i < 7; i++)
    {
        if (record[i] > 1)
        {
            printf("%d*%d", mo[i], record[i]);
            break;
        }
        else if (record[i] == 1)
        {
            printf("%d", mo[i]);
            break;
        }
    }
    i++;
    for (; i < 7; i++)
    {
        if (record[i] > 1)
        {
            printf("+");
            printf("%d*%d", mo[i], record[i]);
        }
        else if (record[i] == 1)
        {
            printf("+");
            printf("%d", mo[i]);
        }
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int sum = CalSum(n, record);
        int n1 = n;
        printf("%d ", sum);
        PrintFormation(record);
        printf("=%d\n", n1);
    }
    return 0;
}