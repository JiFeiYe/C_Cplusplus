#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class Person
{
protected:
    char name[21];
    int eld;
public:
    Person(char* name_, int eld_);
    void display();
};
Person::Person(char* name_, int eld_)
{
    strcpy(name, name_);
    eld = eld_;
}
void Person::display()
{
    cout << name << " " << eld << endl;
}

class notfreeP:public Person//非免听生
{
private:
    double normal, exam, overall;
public:
    notfreeP(char* name_, int eld_, double normal_, double exam_):Person(name_, eld_)
    {
        normal = normal_; exam = exam_;
    }
    char divide();
    void display();
};
char notfreeP::divide()
{
    overall = normal*0.4 + exam*0.6;
    if(overall >= 85)
    {
        return 'A';
    }
    else if(overall >= 75 && overall < 85)
    {
        return 'B';
    }
    else if(overall >= 65 && overall < 75)
    {
        return 'C';
    }
    else if(overall >= 60 && overall < 65)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}
void notfreeP::display()
{
    cout << name << " " << eld << " " << divide() << endl;
}

class freeP:public Person//免听生
{
private:
    double exam, overall;
public:
    freeP(char* name_, int eld_, double exam_):Person(name_, eld_)
    {
        exam = exam_;
    }
    char divide();
    void display();
};
char freeP::divide()
{
    overall = exam;
    if(overall >= 85)
    {
        return 'A';
    }
    else if(overall >= 75 && overall < 85)
    {
        return 'B';
    }
    else if(overall >= 65 && overall < 75)
    {
        return 'C';
    }
    else if(overall >= 60 && overall < 65)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}
void freeP::display()
{
    cout << name << " " << eld << " " << divide() << endl;
}

int main()
{
    int t = 0; cin >> t;
    char name[21];
    int eld = 0;
    char a = ' ';
    int normal = 0, exam = 0;
    while(t--)
    {
        cin >> a;
        if(a == 'R')
        {
            cin >> name >> eld >> normal >> exam;
            notfreeP person(name, eld, normal, exam);
            person.display();
        }
        else if(a == 'S')
        {
            cin >> name >> eld >> exam;
            freeP person(name, eld, exam);
            person.display();
        }
    }
    return 0;
}