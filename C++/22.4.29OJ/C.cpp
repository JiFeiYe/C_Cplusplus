#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class bankAcount//Account
{
private:
    char number[9];
    char type;//P个人，E企业
    int balance;
    char temp;
public:
    bankAcount(char* number, char type, int balance);
    bankAcount(const bankAcount& t);
    void interest();
    void print();
};
bankAcount::bankAcount(char* number_, char type_, int balance_)
{
    strcpy(number, number_);
    type = type_;
    balance = balance_;
    temp = 'H';//H活
}
bankAcount::bankAcount(const bankAcount& t)
{
    strcpy(number, t.number);
    number[0] += 5;
    type = t.type;
    balance = t.balance;
    temp = 'S';//S死
}
void bankAcount::interest()
{
    if(temp == 'H')//活期
    {
        balance += balance * 0.005;
    }
    else if(temp == 'S')
    {
        balance += balance * 0.015;
    }
    cout << "Account=" << number << "--sum=" << balance << endl;
    return;
}
void bankAcount::print()
{
    cout << "Account=" << number << "--";
    if(type == 'P')
    {
        cout << "Person--sum=" << balance << "--";
        if(temp == 'H')
        {
            cout << "rate=0.005" << endl;
        }
        else if(temp == 'S')
        {
            cout << "rate=0.015" << endl;
        }
    }
    else if(type == 'E')
    {
        cout << "Enterprise--sum=" << balance << "--";
        if(temp == 'H')
        {
            cout << "rate=0.005" << endl;
        }
        else if(temp == 'S')
        {
            cout << "rate=0.015" << endl;
        }
    }
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    char number[9] = {" "};
    char type = 'A';
    int balance = 0;
    char operate = 'A';
    while(t--)
    {
        cin >> number >> type >> balance;
        bankAcount A(number, type, balance);
        bankAcount B(A);
        cin >> operate;
        if(operate == 'C')
        {
            A.interest();
        }
        else if(operate == 'P')
        {
            A.print();
        }
        cin >> operate;
        if(operate == 'C')
        {
            B.interest();
        }
        else if(operate == 'P')
        {
            B.print();
        }
    }
    return 0;
}