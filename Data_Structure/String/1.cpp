#include <iostream>
using namespace std;

int nex[1005];
void BuildNxt(char ts[])//ts 模式串
{
    nex[0] = -1;
    for(int i = 0, j = -1; ts[i];)
    {
        if(j == -1 || ts[i] == ts[j])
            nex[++i] = ++j;
        else
            j = nex[j];
    }
}

int main()
{
    char ts[] = "abacad";//nex:-1 0 0 1 1 2 3
    BuildNxt(ts);
    for(int i = 0; i < 20; i++)
    {
        printf("%d ", nex[i]);
    }
    return 0;
}