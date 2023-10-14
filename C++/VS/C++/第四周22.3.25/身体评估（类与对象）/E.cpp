#include <iostream>
#include <cstring>
#include <iomanip> 
using namespace std;

class People
{
private:
	char name[21];
	double height;
	double weight;
	double waistline;//腰围
public:
	/*
	void GetPeople(char* name_, double& height_, double& weight_, double& waistline_)
	{
		strcpy_s(name, name_);
		height = height_;
		weight = weight_;
		waistline = waistline_;
	}*/
	void GetPeople()
	{
		cin >> name >> height >> weight >> waistline;
	}
	int BMI()
	{
		int bmi = 0;
		bmi = int(weight / (height * height) + 0.5);
		return bmi;
	}
	double Centage()
	{
		double cent = 0;
		double a = 0, b = 0;
		a = waistline * 0.74;
		b = weight * 0.082 + 34.89;
		cent = (a - b) / weight;
		return cent;
	}
	void Outname()
	{
		cout << name;
	}
};

int main()
{
	int t = 0;
	cin >> t;
	char name_[21] = { " " };
	double height_ = 0, weight_ = 0, waistline_ = 0;
	People* people = new People[t];
	for (int i = 0; i < t; i++)
	{
		//people->GetPeople(name_, height_, weight_, waistline_);
		people[i].GetPeople();
	}
	for (int i = 0; i < t; i++)
	{
		people[i].Outname();
		cout << "的BMI指数为" << people[i].BMI() << "--体脂率为" << fixed << setprecision(2) << (people+i)->Centage() << endl;
	}
	delete[] people;
	return 0;
}