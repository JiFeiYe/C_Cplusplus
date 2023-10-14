#include <iostream>
using namespace std;

int A[110];
int B[110];
int main()
{
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    int max = A[0], min = B[0];
    for (int i = 1; i < N; i++)
    {
        if (max < A[i])
            max = A[i];
        if (min > B[i])
            min = B[i];
    }
    if (max >= min)
        cout << '0' << endl;
    else
        cout << (min - max + 1) << endl;
    return 0;
}