#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '\\')
        {
            if (str[i+1] == 'n')
            {
                printf("linux\n");
                break;
            }
            else if (str[i+1] == 'r')
            {
                if (str[i+2] == '\\' && str[i+3] == 'n')
                    printf("windows\n");
                else
                    printf("mac\n");
                break;
            }
        }
    }
    return 0;
}