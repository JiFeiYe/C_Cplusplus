#include<iostream>
using namespace std;

class AV
{
private:
    int type;
    string name;
    int price;
    int state;
public:
    AV(int type_, string name_, int price_, int state_);
    void print();
    void count(int day);
};
AV::AV(int type_, string name_, int price_, int state_)
{
    type = type_; name = name_; price = price_; state = state_;
}
void AV::print()
{
    if(type == 1)
    {
        cout << "黑胶片" << "[" << name << "]";
        if(state == 1)
        {
            cout << "已出租" << endl;
        }
        else{
            cout << "未出租" << endl;
        }
    }
    else if(type == 2)
    {
        cout << "CD" << "[" << name << "]";
        if(state == 1)
        {
            cout << "已出租" << endl;
        }
        else{
            cout << "未出租" << endl;
        }
    }
    else if(type == 3)
    {
        cout << "VCD" << "[" << name << "]";
        if(state == 1)
        {
            cout << "已出租" << endl;
        }
        else{
            cout << "未出租" << endl;
        }
    }
    else if(type == 4)
    {
        cout << "DVD" << "[" << name << "]";
        if(state == 1)
        {
            cout << "已出租" << endl;
        }
        else{
            cout << "未出租" << endl;
        }
    }
    return;
}
void AV::count(int day)
{
    if(state == 0)
    {
        print();
        cout << "未产生租金" << endl;
    }
    else
    {
        print();
        cout << "当前租金为" << price*day << endl; 
    }
    return ;
}

int main()
{
    int n = 0;
    cin >> n;
    int type = 0; string name = " "; int price = 0; int state = 0;
    int day = 0;
    while(n--)
    {
        cin >> type >> name >> price >> state;
        AV av(type, name, price, state);
        cin >> day;
        if(day == 0)
        {
            av.print();
        }
        else
        {
            av.count(day);
        }
    }
    //system("pause");
    return 0;
}