/*
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
    char* customerName; // 顾客姓名
    int customerId; // 顾客编号
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel() = default;
    Hotel(char* customer);
    ~Hotel(); //记得delete customerName
    static int Count_();
    static float rent_();
    void Display(); //相应输出顾客姓名、顾客编号、总人数、总收入
};
Hotel::Hotel(char* customer)
{
    customerName = new char[21];
    strcpy_s(customerName, 21, customer);
}
int Hotel::Count_()
{
    totalCustNum++;
    return totalCustNum;
}
float Hotel::rent_()
{
    return rent;
}
void Hotel::Display()
{
    cout << customerName << "2015";
    cout.setf(ios::right);      //设置对齐方式为右对齐 
    cout.fill('0');             //设置填充方式,不足位补0
    cout.width(4);              //设置宽度为4，只对下条输出有用
    cout << Count_();
    cout << Count_() << Count_() * rent_() << endl;
}
Hotel::~Hotel()
{
    delete[] customerName;
}

int main()
{
    float rent = 0;
    cin >> rent;
    while (1)
    {
        char* customer;
        customer = new char[21];
        cin >> customer;
        if (customer[0] == '0') { break; }
        Hotel hotel(customer);
        hotel.Display();
        delete[] customer;
    }
    return 0;
}
*/