#include <iostream>
#include <string.h>
using namespace std;

int Compare(char* S, char* T)
{
	if (int(strlen(S)) > int(strlen(T)))
	{
		return 1;
	}
	else if (int(strlen(S)) < int(strlen(T)))
	{
		return -1;
	}
	else
	{
		int s1 = 0, t1 = 0;
		for (int i = 0; i < 21; i++)
		{
			if (*(S + i) > *(T + i))
			{
				s1++;
			}
			else if (*(S + i) < *(T + i))
			{
				t1++;
			}
			else
			{
				;
			}
		}
		if (s1 > t1)
		{
			return 1;
		}
		else if (s1 < t1)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	int t = 0;
	cin >> t;
	int result = 0;
	char s[21] = {' '};
	char d[21] = {' '};
	for (int i = 0; i < t; i++)
	{
		cin >> s >> d;
		result = Compare(s, d);
		cout << result << endl;
	}
	return 0;
}