#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CBaseAccount
{
protected:
    string name;
    string account;
    int balance;
    int flag1;
public:
    CBaseAccount() = default;
    CBaseAccount(string name_, string account_, int balance_)
    {
        name = name_; account = account_; balance = balance_; flag1 = 0;
    }
    virtual void despoist(int money)
    {
        balance += money;
        return;
    }
    virtual void withdraw(int money)
    {
        if(balance >= money)
        {
            balance -= money;
        }
        else
        {
            cout << "insufficient" << endl;
        }
        return;
    }
    virtual void display()
    {
        cout << name << " " << account << " " << "Balance:" << balance <<endl;
        return;
    }
};

class BasePlus:public CBaseAccount
{
private:
    int limit;
    int limitSum;
public:
    BasePlus() = default;
    BasePlus(string name_, string account_, int balance_): CBaseAccount(name_, account_, balance_)
    {
        limit = 5000; limitSum = 0; flag1 = 0;
    }
    virtual void despoist(int money)
    {
        if(limit == 5000)
        {
            balance += money;
        }
        else if(limit < 5000)
        {
            if((5000 - limit) >= money)
            {
                limit += money;
            }
            else
            {
                balance += (money - (5000 - limit));
                limit = 5000;
            }
        }
        return;
    }
    virtual void withdraw(int money)
    {
        if(balance >= money)
        {
            balance -= money;
        }
        else if(balance < money && (money - balance) <= limit)
        {
            limit -= (money - balance);
            limitSum += (money - balance);
            balance = 0;
        }
        else if(money > balance && (money - balance) > limit)
        {
            cout << "insufficient" << endl;
        }
        else
        {
            cout << "insufficient" << endl;
        }
        return;
    }
    virtual void display()
    {
        cout << name << " " << account << " " << "Balance:" << balance << " ";
        cout << "limit:" << limit << endl;
        return;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    string name = " ", account = " ";
    int balance = 0;
    int money1 = 0, money2 = 0;
    int limit = 0, limitsum = 0;
    while(t--)
    {
        cin >> name >> account >> balance;
        if(account[1] == 'A')
        {
            CBaseAccount BA(name, account, balance);
            cin >> money1 >> money2;
            BA.despoist(money1);
            BA.withdraw(money2);
            cin >> money1 >> money2;
            BA.despoist(money1);
            BA.withdraw(money2);
            BA.display();
        }
        else
        {
            BasePlus BP(name, account, balance);
            cin >> money1 >> money2;
            BP.despoist(money1);
            BP.withdraw(money2);
            cin >> money1 >> money2;
            BP.despoist(money1);
            BP.withdraw(money2);
            BP.display();
        }
    }
    return 0;
}