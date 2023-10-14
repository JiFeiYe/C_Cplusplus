#include<iostream>
using namespace std;

int a[100010][2];
int mergeTemp[100010][2];

void Swap(int indexa, int indexb)
{
    for (int i = 0; i <= 1; i++)
    {
        a[indexa][i] = a[indexa][i] ^ a[indexb][i];
        a[indexb][i] = a[indexb][i] ^ a[indexa][i];
        a[indexa][i] = a[indexa][i] ^ a[indexb][i];
    }
}
void Print(int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i][0] << " " << a[i][1] << endl;
}

void MergeSort(int left, int right)
{
    if (left >= right - 1) return;
    int mid = left + right >> 1;
    MergeSort(left, mid);
    MergeSort(mid, right);
    int i, j, k;
    for (i = k = left, j = mid; i < mid && j < right; )
    {
        mergeTemp[k][0] = a[i][0] <= a[j][0] ? a[i][0] : a[j][0];
        mergeTemp[k++][1] = a[i][0] <= a[j][0] ? a[i++][1] : a[j++][1];
    }
    while (i < mid)
    {
        mergeTemp[k][0] = a[i][0];
        mergeTemp[k++][1] = a[i++][1];
    }
    while (j < right)
    {
        mergeTemp[k][0] = a[j][0];
        mergeTemp[k++][1] = a[j++][1];
    }
    //memcpy(left, right - left);
    for (int i = 0; i <= 1; i++)
    {
        for (int j = left; j < right; j++)
        {
            a[j][i] = mergeTemp[j][i];
        }
    }
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1];
        MergeSort(0, n);
        Print(n);
    }
}