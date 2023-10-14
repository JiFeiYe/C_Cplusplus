#include<iostream>
#include<cstring>
using namespace std;

class Date
{
private:
    int year = 0;
    int month = 0;
    int day = 0;
public:
    Date() = default;
    Date(int year_, int month_, int day_);
    int getyear();
    int getmonth();
    int getday();
};
Date::Date(int year_, int month_, int day_)
{
    year = year_; month = month_; day = day_;
}
int Date::getyear()
{
    return year;
}
int Date::getmonth()
{
    return month;
}
int Date::getday()
{
    return day;
}

class Phone 
{
private:
    char type = ' ';
    char* number = NULL;
    int state = 0;
    Date* date = NULL;
public:
    Phone() = default;
    Phone(char type_, char* number_, int state_);
    Phone(const Phone& phone);
    void Print();
    void Stop(Date date_);
    ~Phone();
};
Phone::Phone(char type_, char* number_, int state_)
{
    type = type_; state = state_;
    number = new char[12];
    strcpy(number, number_);
    cout << "Construct a new phone " << number << endl; 
}
Phone::Phone(const Phone& phone_)
{
    type = 'D'; state = phone_.state;
    number = new char[13];
    strcpy(number, phone_.number);
    cout << "Construct a copy of phone " << number << endl;
    strcat(number, "X");
}
void Phone::Print()
{
    switch(type)
    {
        case 'A': cout << "类型=机构||号码=" << number; break;
        case 'B': cout << "类型=企业||号码=" << number; break;
        case 'C': cout << "类型=个人||号码=" << number; break;
        case 'D': cout << "类型=备份||号码=" << number; break;
    }
    switch(state)
    {
        case 1: cout << "||State=在用" << endl; break;
        case 2: cout << "||State=未用" << endl; break;
        case 3: cout << "||State=停用 ||停机日期=" << date->getyear() << "." << date->getmonth() << "." << date->getday() << endl; break;
    }
}
void Phone::Stop(Date date_)
{
    state = 3;
    date = new Date(date_.getyear(), date_.getmonth(), date_.getday());
    *date = date_;
    cout << "Stop the phone " << number << endl;
}
Phone::~Phone()
{
    if(state == 3)
    {
        delete[] date;
    }
}

int main()
{
    int t = 0;
    cin >> t;
    char type = ' '; char number[12] = {' '}; int state = 0;
    int year = 0; int month = 0; int day = 0;
    while(t--)
    {
        cin >> type >> number >> state >> year >> month >> day;
        Phone phone(type, number, state);
        Date date(year, month, day);
        phone.Print();
        Phone phone_ = phone;
        phone_.Print();
        phone.Stop(date);
        phone.Print();
        cout << "----" << endl;
    }
    return 0;
}