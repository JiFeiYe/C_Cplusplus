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
            if(str[i] != '#')
                s.push(str[i]);
            else
            {
                if(!s.empty())
                    s.pop();
            }
        }
        stack <char> s_;
        int count = 0;
        char ch = ' ';
        len = s.size();
        for(int i = 0; i < len; i++)
        {
            ch = s.top();
            s_.push(s.top());
            s.pop();
        }
        if(s_.empty())
        {
            cout << "NULL" << endl;
        }
        else
        {
            for(int i = 0; i < len; i++)
            {
                ch = s_.top();
                cout << ch;
                s_.pop();
            }
            cout << endl;
        }
    }
    return 0;
}