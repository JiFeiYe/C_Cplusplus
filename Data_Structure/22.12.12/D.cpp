#include<iostream>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int len = str.length();
        string s;
        int p = 0;
        for(int i = 0; i < len; i++)
        {
            if(p != -1 && str[i] != '[' && str[i] != ']')
            {
                s.insert(p, 1, str[i]);
                p++;
            }
            else if(p == -1 && str[i] != '[' && str[i] != ']')
                s += str[i];
            else if(str[i] == '[' )
                p = 0;
            else if(str[i] == ']')
                p = -1;
        }
        cout << s << endl;
    }
    return 0;
}