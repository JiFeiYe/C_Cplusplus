#include <iostream>
#include <stack>
using namespace std;

char str[110];
stack<char> st;
int main()
{
    int i = 0;
    while (cin >> str[i++]);
    int flag = 1;
    for(int j = 0; j < i; j++)
    {
        if(str[j] == '(' || str[j] == '[' || str[j] == '{')
        {
            st.push(str[j]);
        }
        else if(st.empty() && (str[j] == ')' || str[j] == ']' || str[j] == '}'))
        {
            flag = 0;
            break;
        }
        else if(!st.empty())
        {
            if(str[j] == ')' && st.top() == '(')
                st.pop();
            else if(str[j] == ']' && st.top() == '[')
                st.pop();
            else if(str[j] == '}' && st.top() == '{')
                st.pop();
        }
    }
    if(flag == 1 && st.empty())
        cout << "Yes";
    else if(flag == 0)
        cout << "No";
    else
        cout << "No";
    return 0;
}