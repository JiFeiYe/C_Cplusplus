#include<iostream>

int nex[10005];
void BuildNext(std::string ts)
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
    int T = 0;
    scanf("%d", &T);
    std::string str;
    int len = 0;
    while(T--)
    {
        int num = 0;
        std::cin >> str;
        BuildNext(str);
        len = str.length();
        int L = len - nex[len];
        if(len % L == 0 && len/L != 1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", L-nex[len]%L);
        }
    }
    return 0;
}