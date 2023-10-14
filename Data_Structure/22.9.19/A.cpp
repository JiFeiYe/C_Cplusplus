#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        string str = " ";
        cin >> str;
        int len = str.length();
        stack <char> s;
        for(int i = 0; i < len; i++)
        {
            s.push(str[i]);
        }
        char ch = ' ';
        for(int i = 0; i < len; i++)
        {
            ch = s.top();
            cout << ch;
            s.pop();
        }
        cout << endl;
    }
    return 0;
}