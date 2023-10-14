#include<iostream>
#include<string>
using namespace std;

int nex[1000];

void BuildNext(string ts, int *next)//nex计算
{
    next[0] = -1;
    for(int i = 0, j = -1; ts[i];)
    {
        if(j == -1 || ts[i] == ts[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    string str;
    int len;
    int count = 0;
    while(t--)
    {
        cin >> str;
        len = str.length();
        count = 0;
        for(int j = 0; j < len; j++)
        {
            BuildNext(str, nex);
            for(int i = 0; i <= len; i++)
            {
                if(count < nex[i])
                    count = nex[i];
            }
            str.erase(0, 1);//删除从0开始的1个字符(第一个字符)
        }
        if(count != 0)
            cout << count << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}