#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CTravel_Card
{
protected:
    int id1;
    float points1;//vip积分
public:
    CTravel_Card() = default;
    CTravel_Card(int id1_){
        id1 = id1_; points1 = 0;
    }
};

class CCredit_Card
{
protected:
    int id2;
    string name;
    float amount;//额度
    float bill;//账单
    float points2;//信用卡积分
public:
    CCredit_Card() = default;
    CCredit_Card(int id2_, string name_, int amount_){
        id2 = id2_; name = name_; amount = amount_, bill = 0, points2 = 0;
    }
    void pay(float payout);
    void refund(float payin);
};
void CCredit_Card::pay(float payout)
{
    if(payout < amount)
    {
        amount -= payout;//额度
        bill += payout;//账单
        points2 += payout;
    }
    return;
}
void CCredit_Card::refund(float payin)
{
    amount += payin;
    bill -= payin;
    points2 -= payin;
    return;
}

class CTravel_Credit_Card:public CTravel_Card, public CCredit_Card
{
public:
    CTravel_Credit_Card() = default;
    CTravel_Credit_Card(int id1_, int id2_, string name_, float amount_):CTravel_Card(id1_), CCredit_Card(id2_, name_, amount_){}
    void operate(char a, float m);
    void print();
};
void CTravel_Credit_Card::operate(char a, float m)
{
    if(a == 'o')
    {
        points1 += m;
        pay(m);
    }
    else if(a == 'c')
    {
        pay(m);
    }
    else if(a == 'q')
    {
        refund(m);
    }
    else if(a == 't')//判断积分够不够？
    {
        points1 += m / 2;
        points2 -= m;
    }
    else
    {
        cout << "error" << endl;
    }
    return;
}
void CTravel_Credit_Card::print()
{
    cout << id1 << " " << int(points1) << endl;
    cout << id2 << " " << name << " " << bill << " " << int(points2) << endl;
}

int main()
{
    int id1 = 0, id2 = 0;
    string name = " ";
    float amount = 0;
    cin >> id1 >> id2 >> name >> amount;
    CTravel_Credit_Card card(id1, id2, name, amount);
    int n = 0;
    cin >> n;
    char operate = ' ';
    float money = 0;
    while(n--)
    {
        cin >> operate >> money;
        card.operate(operate, money);
    }
    card.print();
    return 0;
}