#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &x, int &y)
{
    x = x^y;
    y = x^y;
    x = x^y;
}

int main()
{
    int a[100];
    int i;
    for (i = 0; i <= 99; ++i)
        a[i] = i;
    for (i = 99; i >= 1; --i)
        swap(a[i], a[rand() % i]);
    return 0;
}