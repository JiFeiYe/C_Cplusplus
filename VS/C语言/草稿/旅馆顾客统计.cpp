/*
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Hotel
{
private:
    static int totalCustNum; // �˿�������
    static float totalEarning; // �õ�������
    static float rent; // ÿ���˿͵ķ���
    char* customerName; // �˿�����
    int customerId; // �˿ͱ��
public:
    // totalCustNum++��customerId����totalCustNum����
    Hotel() = default;
    Hotel(char* customer);
    ~Hotel(); //�ǵ�delete customerName
    static int Count_();
    static float rent_();
    void Display(); //��Ӧ����˿��������˿ͱ�š���������������
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
    cout.setf(ios::right);      //���ö��뷽ʽΪ�Ҷ��� 
    cout.fill('0');             //������䷽ʽ,����λ��0
    cout.width(4);              //���ÿ��Ϊ4��ֻ�������������
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