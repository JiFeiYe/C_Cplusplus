#include<iostream>
#include<string.h>
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
int KmpMatch(char ms[], char ts[])//ms 主串
{
    int tlen = strlen(ts);
    for(int i = 0, j = 0; ms[i];)
    {
        if(j == -1 || ms[i] == ts[j])
        {
            if(j == tlen - 1)
            {    
                //自定义区域
                return i - tlen + 1;//返回匹配位置
            }
            else
                i++, j++;
        }
        else
            j = nex[j];
    }
    return -1;//匹配失败
}

int main()
{
    char ts[] = "abaabac";//nex:-1 0 0 1 1 2 3
    char ms[] = "ababaabaabac";
    BuildNxt(ts);
    for(int i = 0; i < 8; i++)
    { 
        cout << nex[i] << " ";
    }
    cout << endl << KmpMatch(ms, ts) << endl;
    return 0;
} 