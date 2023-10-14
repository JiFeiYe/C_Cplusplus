#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Phone_num
{
private:
    int number;
    char type;//类型A政府B企业C个人
    int state;//状态01
    char* name = NULL;
public:
    void writePhone(int number_, char type_, int state_, char* name);
    void print();
    int getnumber();
    ~Phone_num();
};
void Phone_num::writePhone(int number_, char type_, int state_, char* name_)
{
    number = number_;
    type = type_;
    state = state_;
    name = new char[21];
    strcpy(name, name_);
    cout << number << " constructed." << endl;
}
void Phone_num::print()
{
    cout << "Phone=" << number << "--Type=" << type << "--State=";
    if(state == 1)
    {
        cout << "use--Owner=" << name << endl;
    }
    else
    {
        cout << "unuse--Owner=" << name << endl;
    }
}
int Phone_num::getnumber()
{
    return number;
}
Phone_num::~Phone_num()
{
    cout << number << " destructed." << endl;
    delete[] name;
}

int main()
{
    int number = 0;
    char type = 'A';
    int state = 0;
    char name[21] = {" "};
    Phone_num phone[3];
    for(int i = 0; i < 3; i++)
    {
        cin >> number >> type >> state >> name;
        phone[i].writePhone(number, type, state, name);
    }
    int t = 0;
    cin >> t;
    int count = 0;
    while(t--)
    {
        cin >> number;
        count = 0;
        for(int i = 0; i < 3; i++)
        {
            if(number == phone[i].getnumber())
            {
                phone[i].print();
            }
            else
            {
                count++;
            }
        }
        if(count == 3)
        {
            cout << "wrong number." << endl;
        }
    }
    return 0;
}