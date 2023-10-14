#include<iostream>
#include<cstring>
using namespace std;

int nex[100005];
void BuildNext(char ts[])
{
    nex[0] = -1;
    for (int i = 0, j = -1; ts[i];)
    {
        if (j == -1 || ts[i] == ts[j])
            nex[++i] = ++j;
        else
            j = nex[j];
    }
}
int KmpMatch(char ms[], char ts[])
{
    int count = 0;
    int tlen = strlen(ts);
    for (int i = 0, j = 0; ms[i];)
    {
        if (j == -1 || ms[i] == ts[j])
        {
            if (j == tlen - 1)//操作处
            {
                count++;
                j = 0; i -= (tlen - 2);
            }
            else
                i++, j++;
        }
        else
            j = nex[j];
    }
    return count;
}

char ms[100005], ts[55];
int main()
{
    int N = 0;
    while (cin >> ms)
    {
        cin >> N;
        while (N--)
        {
            cin >> ts;
            BuildNext(ts);
            cout << ts << ":" << KmpMatch(ms, ts) << endl;
        }
    }
    return 0;
}