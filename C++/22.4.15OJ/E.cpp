#include<iostream>
using namespace std;

class Account
{
private:
    static float count; // 所有账户总余额
    static float interestRate; // 利率
    string accno, accname; // 账号 姓名
    float balance; // 余额
public:
    Account() = default;
    void account(string ac, string na, float ba);
    void deposit(float amount); // 存款
    void withdraw(float amount); // 取款
    float getBalance(); // 获取账户余额
    static float getCount(); // 获取账户总余额
    static void setInterestRate(float rate); // 设置利率
    static float getInterestRate(); // 获取利率
    void show(); // 显示账户所以基本信息
    friend void update(Account& a);
    ~Account();
};
float Account::count = 0;
float Account::interestRate = 0;
void Account::account(string ac, string na, float ba)
{
    accno = ac; accname = na; balance = ba;
}
void Account::deposit(float amount) // 存款
{
    balance += amount;
}
void Account::withdraw(float amount) // 取款
{
    balance -= amount;
}
float Account::getBalance() // 获取账户余额
{
    return balance;
}
float Account::getCount() // 获取所有账户总余额
{
    return count;
}
void Account::setInterestRate(float rate) // 设置利率
{
    interestRate = rate;
}
float Account::getInterestRate() // 获取利率
{
    return interestRate;
}
void Account::show() // 显示账户基本信息
{
    cout << accno << " " << accname << " ";
}
void update(Account& a) // 友元
{
    a.balance =  a.balance + a.balance * a.interestRate;
}
Account::~Account()
{}

int main()
{
    float rate = 0, ba = 0;
    int n = 0;
    cin >> rate >> n;
    Account* acc = new Account[n];
    for(int i = 0; i < n; i++)
    {
        acc[i].setInterestRate(rate);
    }
    string ac = " ", na = " ";
    float inbal = 0, outbal = 0;
    int temp = 0;
    int n_ = n;
    while(n--)
    {
        cin >> ac >> na >> ba >> inbal >> outbal;
        acc[temp].account(ac, na, ba);
        acc[temp].show();//ac na
        acc[temp].deposit(inbal);//存入
        cout << acc[temp].getBalance() << " ";//现有存款
        update(acc[temp]);//计算利息
        cout << acc[temp].getBalance() << " ";//算利息后存款
        acc[temp].withdraw(outbal);//取出
        cout << acc[temp].getBalance() << endl;//取款后存款
        temp++;
    }
    float total = 0;
    for(int i = 0; i < n_; i++)
    {
        total += acc[i].getBalance();
    }
    cout << total << endl;
    return 0;
}