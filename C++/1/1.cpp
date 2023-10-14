#include<stdio.h>
#include<math.h>
int max(int a)
{
    int b = a / 100;
    int c = a % 100 / 10;
    int d = a % 10;
    int i;
    if (b < c)
    {
        i = b;
        b = c;
        c = i;
    }
    if (b < d)
    {
        i = b;
        b = d;
        d = i;
    }
    if (c < d)
    {
        i = c;
        c = d;
        d = i;
    }
    int A = b * 100 + c * 10 + d;
    return A;
}
int min(int a)
{
    int b = a / 100;
    int c = a % 100 / 10;
    int d = a % 10;
    int i;
    if (b > c)
    {
        i = c;
        c = b;
        b = i;
    }
    if (b > d)
    {
        i = d;
        d = b;
        b = i;
    }
    if (c > d)
    {
        i = d;
        d = c;
        c = i;
    }
    int B = b * 100 + c * 10 + d;
    return B;
}
int main()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 1; n != 495; i++)
    {
        int A = max(n);
        int B = min(n);
        int n = A - B;
        printf("%d\n", n);
        printf("%d: %d - %d = %d\n", i, A, B, n);
    }
    return 0;
}