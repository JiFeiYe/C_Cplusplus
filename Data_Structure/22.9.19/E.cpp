#include<iostream>
#include<stack>
#include<math.h>
#include<string>
using namespace std;

string str = " ";
stack <char> s_temp;//临时栈
stack <string> s2;//输出栈||结果栈
stack <char> s3;//运算符栈
int temp_int = 0;
string temp_str = " ";
int flag = 0;

void clear()
{
    while(!s_temp.empty())
    {
        s_temp.pop();
    }
    while(!s2.empty())
    {
        s2.pop();
    }
    while(!s3.empty())
    {
        s3.pop();
    }
    temp_int = 0;
    return;
}

void PN()//参考RPN();
{
    clear();
    int len = str.length();
    for(int i = len-1; i >= 0; i--)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(str[i-1] >= '0' && str[i-1] <= '9')
            {
                flag = 1;
                continue;
            }
            else
            {
                for(int j = i;; j++)
                {
                    if(flag == 0)
                    {
                        string temp_str(1, str[j]);
                        s2.push(temp_str);
                        break;
                    }
                    else 
                    {
                        temp_int = temp_int * 10 + (str[j]-48);
                        if(!(str[j+1] >= '0' && str[j+1] <= '9'))
                        {
                            temp_str = to_string(temp_int);
                            s2.push(temp_str);
                            flag = 0;
                            temp_int = 0;
                            break;
                        }
                    }
                }
            }
        }
        if(str[i] == ')')
        {
            while(!s_temp.empty())
            {
                s_temp.pop();
            }
            s3.push(str[i]);
        }
        while(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while(!s_temp.empty())
            {
                s_temp.pop();
            }
            if(s3.empty() || s3.top() == ')' )
            {
                s3.push(str[i]);
                break;
            }
            else
            {
                if(str[i] == '+' || str[i] == '-')
                {
                    if(s3.top() != '+' && s3.top() != '-')
                    {
                        string temp_str(1,s3.top());
                        s2.push(temp_str);
                        s3.pop();
                    }
                    else
                    {
                        s3.push(str[i]);
                        break;
                    }
                }
                if(str[i] == '*' || str[i] == '/')
                {
                    s3.push(str[i]);
                    break;
                }
            }
        }
        if(str[i] == '(')
        {
            while(!s_temp.empty())
            {
                s_temp.pop();
            }
            while(s3.top() != ')')
            {
                string temp_str(1,s3.top());
                s2.push(temp_str);
                s3.pop();
            }
            s3.pop();
        }
    }
    while(!s3.empty())
    {
        string temp_str(1,s3.top());
        s2.push(temp_str);
        s3.pop();
    }
    cout << s2.top();
    s2.pop();
    while(!s2.empty())
    {
        cout << " " << s2.top();
        s2.pop();
    }
    cout << endl;
}

void RPN()
{
    clear();
    int len = str.length();
    for(int i = 0; i < len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            temp_int = temp_int * 10 + (str[i] - 48);
            if(str[i+1] < '0' || str[i+1] > '9')
            {
                temp_str = to_string(temp_int);
                s2.push(temp_str);
                temp_int = 0;
            }
        }
        if(str[i] == '(')
        {
            while(!s_temp.empty())
            {
                s_temp.pop();
            }
            s3.push(str[i]);
        }
        while(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while(!s_temp.empty())
            {
                s_temp.pop();
            }
            if(s3.empty() || s3.top() == '(' )
            {
                s3.push(str[i]);
                break;
            }
            else
            {
                if(str[i] == '+' || str[i] == '-')
                {
                    string temp_str(1,s3.top());
                    s2.push(temp_str);
                    s3.pop();
                }
                if(str[i] == '*' || str[i] == '/')
                {
                    s3.push(str[i]);
                    break;
                }
            }
        }
        if(str[i] == ')')//碰到右括号就把运算符栈括号中的操作符出栈放至输出栈
        {
            while(!s_temp.empty())
            {
                s_temp.pop();
            }
            while(s3.top() != '(')
            {
                string temp_str(1,s3.top());
                s2.push(temp_str);
                s3.pop();
            }
            s3.pop();//左括号去掉
        }
    }
    while(!s3.empty())
    {
        string temp_str(1,s3.top());
        s2.push(temp_str);
        s3.pop();
    }
    stack <string> s4;
    while(!s2.empty())
    {
        s4.push(s2.top());
        s2.pop();
    }
    cout << s4.top();
    s4.pop();
    while(!s4.empty())
    {
        cout << " " << s4.top();
        s4.pop();
    }
    cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        cin >> str;
        PN();
        RPN();
        cout << endl;
    }
    return 0;
}