#include <iostream>
#include <cstring>
using namespace std;

class Cats
{
private:
	char name[31];
	int weight;
public:
	Cats(){};
	void GetCat(char* name_,int weight_)
	{
		strcpy_s(name, name_);
		weight = weight_;
	}
	int get()
	{
		return weight;
	}
	void Outname()
	{
		cout << name << " ";
	}
};

struct cattemp
{
	char name;
	int weight;
};
int main()
{
	int n = 0;
	cin >> n;
	Cats* cat = new Cats[n];
	char name_[31] = { " " };
	int weight_ = 0;
	for (int i = 0; i < n; i++)//≥ı ºªØ
	{
		cin >> name_ >> weight_;
		cat[i].GetCat(name_, weight_);
	}
	int* a = new int[n];//≈≈–Ú
	for (int i = 0; i < n; i++)
	{
		a[i] = cat[i].get();
	}
	int temp = 0;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] >= a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == cat[j].get())
			{
				cat[j].Outname();
			}
		}
	}
	delete[] cat;
	delete[] a;
	return 0;
}