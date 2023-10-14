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
    std::string ms, ts, str;
    int len = 0, len_ = 0;
    while (t--)
    {
        std::cin >> ms >> ts >> str;
        std::cout << ms << std::endl;
        len = str.length();
        len_ = ts.length();
        BuildNext(ts);
        int n = KmpMatch(ms, ts);
        if (n == -1)
        {
            std::cout << ms << std::endl;
            continue;
        }
        else
        {
            if(ts.length() == len)
            {
                for(int i = n; i < len + n; i++)
                {
                    ms[i] = str[i-n];
                }
                std::cout << ms << std::endl;
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    std::cout << ms[i];
                }
                std::cout << str;
                for(int i = len_ + n; ms[i]; i++)
                {
                    std::cout << ms[i];
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}