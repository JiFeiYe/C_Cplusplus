#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Hotel
{
private:
    static int totalCustNum; // 顾客总人数
    static float totalEarning; // 旅店总收入
    static float rent; // 每个顾客的房租
    char *customerName; // 顾客姓名
    int customerId; // 顾客编号
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel() = default;
    Hotel(char* customer);
    ~Hotel(); //记得delete customerName
    void Display(); //相应输出顾客姓名、顾客编号、总人数、总收入
    static void setrent(float rent_);
};
int Hotel::totalCustNum = 0;
float Hotel:: rent = 0;
float Hotel:: totalEarning = 0;
Hotel::Hotel(char* customer)
{
    customerName = new char[strlen(customer) + 1];
    strcpy(customerName, customer);
    customerId = 20150000 + ++totalCustNum;
    totalEarning = rent * totalCustNum;
}
void Hotel::Display()
{
    cout << customerName << " " << customerId << " " << totalCustNum << " " << totalEarning << endl;
}
void Hotel::setrent(float rent_)
{
    rent = rent_;
}
Hotel::~Hotel()
{
    delete[] customerName;
}

int main()
{
    float rent = 0;
    cin >> rent;
    Hotel::setrent(rent);
    while(1)
    {
        char customer[100];
        cin >> customer;
        if(customer[0] == '0'){break;}
        Hotel hotel(customer);
        hotel.Display();
    }
    return 0;
}