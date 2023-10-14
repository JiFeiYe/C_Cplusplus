#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		char c[21] = {' '};
		char a[21] = {' '};
		cin >> c >> a;
		char* C = c; 
		char* A = a;

		int c1 = int(strlen(c));
		int a1 = int(strlen(a));
		
		string s = " ";
		string* S = &s;

		for (int i = 0; i < c1; i++)
		{
			*C = *C + *A - '0';
			if (*C > 'Z' && *C < 'a' || *C > 'z')
			{
				*C = *C - 26;
			}
			C++; A++;
			if (*A == '\0')
			{
				A = a;
			}
		}
		*S = c;
		cout << *S << endl;
	}
	return 0;
}