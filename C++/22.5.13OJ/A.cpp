#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CPeople 
{
protected:
    string name;
    char sex;
    int eld;
public:
    CPeople() = default;
    CPeople(string name_, char sex_, int eld_){
        name = name_; sex = sex_; eld = eld_;
    }
    void print();
};
void CPeople::print()
{
    cout <<"Name: " << name << endl << "Sex: " << sex << endl << "Age: " << eld << endl;
}

class CStudent:virtual public CPeople
{
protected:
    int id;
    double score;
public:
    CStudent() = default;
    CStudent(string name_, char sex_, int eld_, int id_, double score_):CPeople(name_, sex_, eld_){
        id = id_; score = score_;
    }
    void print();
};
void CStudent::print()
{
    CPeople::print();
    cout << "No.: " << id << endl << "Score: " << score << endl << endl;
}

class CTeacher:virtual public CPeople
{
protected:
    string position;
    string department;
public:
    CTeacher() = default;
    CTeacher(string name_, char sex_, int eld_, string position_, string department_):CPeople(name_, sex_, eld_){
        position = position_; department = department_;
    }
    void print();
};
void CTeacher::print()
{
    CPeople::print();
    cout << "Position: " << position << endl << "Department: " << department << endl << endl;
}

class CGradOnWork:public CStudent,public CTeacher
{
private:
    string direction;
    string tutor;
public:
    CGradOnWork() = default;
    CGradOnWork(string name_, char sex_, int eld_, int id_, double score_, string position_, string department_, string direction_, string tutor_):CPeople(name_, sex_, eld_), CStudent(name_, sex_, eld_, id_, score_), CTeacher(name_, sex_, eld_, position_, department_){
        direction = direction_; tutor = tutor_;
    }
    void print();
};
void CGradOnWork::print()
{
    CPeople::print();
    cout << "No.: " << id << endl << "Score: " << score << endl << "Position: " << position << endl << "Department: " << department << endl;
    cout << "Direction: " << direction << endl << "Tutor: " << tutor << endl;
}

int main()
{
    string name = " ";
    char sex = ' ';
    int eld = 0;
    int id = 0;
    double score = 0;
    string position = " ";
    string department = " ";
    string direction = " ";
    string tutor = " ";
    cin >> name >> sex >> eld;
    cin >> id >> score;
    cin >> position >> department;
    cin >> direction >> tutor;
    CGradOnWork a(name, sex, eld, id, score, position, department, direction, tutor);
    cout << "People:" << endl;
    a.CPeople::print();
    cout << endl << "Student:" << endl;
    a.CStudent::print();
    cout << "Teacher:" << endl;
    a.CTeacher::print();
    cout << "GradOnWork:" << endl;
    a.print();
    return 0;
}