//#include<iostream>
//#include<iomanip>
//#include<cstring>
//#include<cmath>
//using namespace std;
//
//class Person
//{
//protected:
//    char name[21];
//    int eld;
//public:
//    Person(char* name_, int eld_);
//    void display();
//};
//Person::Person(char* name_, int eld_)
//{
//    strcpy(name, name_);
//    eld = eld_;
//}
//void Person::display()
//{
//
//}
//
//class freeP :public Person//ÃâÌýÉú
//{
//private:
//    double normal, exam, overall;
//public:
//    freeP(char* name_, int eld_, double normal_, double exam_) :Person(name_, eld)
//    {
//        normal = normal_; exam = exam_;
//    }
//    void display();
//};
//
//class notfreeP :public Person//·ÇÃâÌýÉú
//{
//private:
//    double exam, overall;
//public:
//    notfreeP(char* name_, int eld_, double exam_) :Person(name_, eld)
//    {
//        exam = exam_;
//    }
//    void display();
//};
//
//int main()
//{
//    int t = 0; cin >> t;
//    char name[21];
//    int eld = 0;
//    char a = ' ';
//    int normal = 0, exam = 0;
//    while (t--)
//    {
//        cin >> a;
//        if (a == 'R')
//        {
//            cin >> name >> eld >> normal >> exam;
//            notfreeP person(name, eld, normal, exam);
//        }
//        else if (a == 'S')
//        {
//
//        }
//    }
//}