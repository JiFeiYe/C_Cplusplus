#include <iostream>
using namespace std;

string reverse(string str, int slen)
{
    string rstr;
    for (int i = 0; i < slen; i++)
    {
        rstr += str[slen - i - 1];
    }
    return rstr;
}

int main()
{
    string str = " ";
    cin >> str;
    int slen = str.size();
    for (int i = slen - 1; i >= 0; i--)
    {
        if (str[i] == '0')
            slen--;
        else
            break;
    }
    string rstr = reverse(str, slen);
    bool bo = true;
    for(int i = 0; i < slen; i++)
    {
        if(str[i] != rstr[i])
        {
            bo = false;
            break;
        }
    }
    if(bo)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}