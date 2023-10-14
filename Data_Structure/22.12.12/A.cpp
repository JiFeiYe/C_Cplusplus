#include<iostream>
using namespace std;

string str[100010];
string mergeTemp[100010];
int n;

void Swap(int indexa, int indexb)
{
    string strtemp = str[indexa];
    str[indexa] = str[indexb];
    str[indexb] = strtemp;
}
int Compare(string s1, string s2)//return s1 < s2 ? 1 : 0;
{
    int len1 = s1.size(), len2 = s2.size();
    int min1 = len1 < len2 ? len1 : len2;
    for(int i = 0; i < min1; i++)
    {
        if(s1[i] < s2[i])
            return 1;
        else if(s1[i] > s2[i])
            return 0;
    }
    if(min1 == len1)
        return 1;
    else 
        return 0;
}
void Print()
{
    cout << str[0];
    for (int i = 1; i < n; i++)
        cout << " " << str[i];
    cout << endl;
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
        mergeTemp[k++] = Compare(str[i], str[j]) ? str[j++] : str[i++];
    }
    while (i < mid)
    {
        mergeTemp[k++] = str[i++];
    }
    while (j < right)
    {
        mergeTemp[k++] = str[j++];
    }
    //memcpy(left, right - left);
    for (int j = left; j < right; j++)
    {
        str[j] = mergeTemp[j];
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> str[i];
        MergeSort(0, n);
        Print();
    }
    return 0;
}