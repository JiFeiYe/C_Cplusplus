//#include<iostream>
//#include <stack>
//#include <string>
//#include<cmath>
//
//using namespace std;
//void show(stack<char>a);
//int com(char a, char b);
//void prior(string str, int len);
//void behind(string str, int len);
//
//int main(void)
//{
//	int t, i;
//	cin >> t;
//	string str;
//	int len;
//	while (t--)
//	{
//		cin >> str;
//		len = str.length();
//		prior(str, len);
//		behind(str, len);
//	}
//	return 0;
//}
//
//void show(stack<char>a)
//{
//	char ch;
//	stack<char>b;
//	while (!a.empty())
//	{
//		b.push(a.top());
//		a.pop();
//	}
//	while (!b.empty())
//	{
//		ch = b.top();
//		cout << ch;
//		b.pop();
//	}
//	cout << endl;
//}
//
//int com(char a, char b)
//{
//	int f1, f2;
//	if (a == '+' || a == '-')
//	{
//		f1 = 1;
//	}
//	else
//	{
//		f1 = 2;
//	}
//	if (b == '+' || b == '-')
//	{
//		f2 = 1;
//	}
//	else
//	{
//		f2 = 2;
//	}
//	if (f1 <= f2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//void prior(string s, int len)
//{
//
//}
//
//void behind(string str, int len)
//{
//	int i;
//	stack<char>one;//´æ·ûºÅ Ñ¹Õ»
//	stack<char>answer;//Êä³ö´ð°¸
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == '(')
//		{
//			one.push(str[i]);
//		}
//		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')//ÈëÕ»
//		{
//			while (!one.empty() && com(str[i], one.top()))
//			{
//				answer.push(one.top());
//				answer.push(' ');
//				one.pop();
//			}
//			one.push(str[i]);
//		}
//		else if (str[i] == ')')
//		{
//			while (one.top() != '(')
//			{
//				answer.push(one.top());
//				answer.push(' ');
//				one.pop();
//			}
//			one.pop();//É¾³ý×óÀ¨ºÅ
//		}
//		else if (str[i] >= '0' && str[i] <= '9')
//		{
//			while (str[i] >= '0' && str[i] <= '9' && i < len)
//			{
//				answer.push(str[i]);
//				i++;
//			}
//			answer.push(' ');
//			i--;
//		}
//	}
//	while (!one.empty())
//	{
//		answer.push(one.top());
//		answer.push(' ');
//		one.pop();
//	}
//	show(answer);
//}