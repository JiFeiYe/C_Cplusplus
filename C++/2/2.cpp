#include<iostream>
#include <crtdbg.h>
using namespace std;

class Subject
{
private:
	string subject_name;
	int D, C;
	int C_div_D;
public:
	Subject() {}
	void set_v(int d,int c,string name)
	{
		D = d;
		C = c;
		subject_name = name;
		C_div_D = c - d;
	}
	void set_C_div_D(int t)
	{
		C_div_D -= t;
	}
	int get_C_div_D()
	{
		return C_div_D;
	}
	string get_name()
	{
		return subject_name;
	}
};

int main()
{
	int N, T;
	cin >> N >> T;
	int d, c;
	string name;
	
	Subject* p = new Subject[N];
	while (T--)
	{
		int temp = N;
		while (temp--)
		{
			cin >> name >> d >> c;
			(p++)->set_v(d, c, name);
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 1; j < N; j++)
			{
				if (p[i].get_C_div_D() > p[j].get_C_div_D())
				{
					Subject tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			cout << p[i].get_name() << endl;
		}
	}
    system("pause");
	return 0;
}