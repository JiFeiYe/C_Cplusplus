#include<iostream>
#include<string>
using namespace std;

int nex[1000];
string str_;

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

string matched_Prefix_Postfix(string str)
{
    str_ = "";
    BuildNext(str, nex);
    int len = str.length();
    if(nex[len] > 0)
    {
        for(int i = 0; i < nex[len]; i++)
        {
            str_ += str[i];
        }
        return str_;
    }
    else if(nex[len-1] == 0 && str[0] == str[len-1])
    {
        str_ = str[0];
        return str_;
    }
    else
        return "error";
}

int main()
{
    int n = 0;
    cin >> n;
    string str;
    int len = 0;
    string str__ = " ";
    while(n--)
    {
        cin >> str;
        len = str.length();
        str__ = matched_Prefix_Postfix(str);
        if(str__ != "error")
        {
            cout << str__ << endl;
        }
        else
        {
            cout << "empty" << endl;
        }
    }
    return 0;
}