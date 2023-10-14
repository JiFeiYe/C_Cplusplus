#include<iostream>

int nex[1005];
void BuildNext(std::string ts)
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
int KmpMatch(std::string ms, std::string ts)
{
    int tlen = ts.length();
    for (int i = 0, j = 0; ms[i];)
    {
        if (j == -1 || ms[i] == ts[j])
        {
            if (j == tlen - 1)
            {
                return i - tlen + 1;
            }
            else
                i++, j++;
        }
        else
            j = nex[j];
    }
    return -1;
}

int main()
{
    int t = 0;
    std::cin >> t;
    std::string ms, ts;
    int len = 0;
    while (t--)
    {
        std::cin >> ms >> ts;
        len = ts.length();
        BuildNext(ts);
        int n = KmpMatch(ms, ts);
        //std::cout << nex[0];
        for(int i = 0; i < len; i++)
        {
            std::cout  << nex[i] << " ";
        }
        std::cout << std::endl;
        if(n != -1)
            std::cout << n+1 << std::endl;
        else
            std::cout << '0' << std::endl;
    }
    return 0;
}