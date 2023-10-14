//#include<iostream>
//#include<stack>
//using namespace std;
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    while (t--)
//    {
//        string str = " ";
//        cin >> str;
//        int len = str.length();
//        stack <char> s;
//        int flag = 0;
//        for (int i = 0; i < len; i++)
//        {
//            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
//                s.push(str[i]);
//            if (str[i] == ')')
//            {
//                if (s.top() == '(' && !s.empty())
//                {
//                    s.pop();
//                }
//                else
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//            if (str[i] == ']')
//            {
//                if (s.top() == '[' && !s.empty())
//                {
//                    s.pop();
//                }
//                else
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//            if (str[i] == '}')
//            {
//                if (s.top() == '{' && !s.empty())
//                {
//                    s.pop();
//                }
//                else
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//        }
//        if (s.empty() && flag == 0)
//        {
//            cout << "ok" << endl;
//        }
//        else if (!s.empty() || flag == 1)
//        {
//            cout << "error" << endl;
//        }
//    }
//    return 0;
//}