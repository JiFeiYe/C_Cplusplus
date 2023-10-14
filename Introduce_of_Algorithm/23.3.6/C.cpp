#include <iostream>
using namespace std;

int Modd[200];
int main()
{
    int N = 0;
    cin >> N;
    int *A = new int[N];
    int i = N, j = 0;
    while (i)
        cin >> A[--i];
    int mmod = 0;
    for (i = 0; i < N; i++)
    {
        mmod = A[i] % 200;
        Modd[mmod]++;
    }
    int count = 0;
    for (int i = 0; i < 200; i++)
    {
        if (Modd[i] != 0)
        {
            count += Modd[i] * (Modd[i] - 1) / 2;
        }
    }
    cout << count << endl;
    delete A;
    return 0;
}
/*
6
123 223 123 523 200 2000
*/