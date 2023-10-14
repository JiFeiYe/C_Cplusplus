#include<iostream>
#include<cstring>
using namespace std;

class CRelNumber
{
private:
    char* Number;
public:
    CRelNumber();
    CRelNumber(char* Num);
    CRelNumber(CRelNumber& Num_);
    ~CRelNumber();
};
CRelNumber::CRelNumber()
{
    Number = new char[100];
}
CRelNumber::CRelNumber(char* Num)
{
    Number = new char[100];
    strcpy(Number, Num);
}
CRelNumber::CRelNumber(CRelNumber& Num_)
{
    Number = new char[100];
    strcpy(Number, Num_.Number);
    if (Num_.Number[0] >= '2' && Num_.Number[0] <= '4')
    {
        cout << "8" << Number << endl;
    }
    else if (Num_.Number[0] >= '5' && Num_.Number[0] <= '8')
    {
        cout << "2" << Number << endl;
    }
}
CRelNumber::~CRelNumber()
{
    delete[] Number;
}

int main()
{
    int t = 0;
    cin >> t;
    char* num = new char[8];
    while (t--)
    {
        cin >> num;
        int flag = 1;
        for (int i = 0; i < strlen(num); i++)
        {
            if (num[i] < 48 || num[i] > 57)
            {
                flag = 0;
            }
        }
        if (num[0] >= '2' && num[0] <= '8' && strlen(num) == 7 && flag == 1)
        {
            CRelNumber crelnumber(num);
            CRelNumber crelnumber_ = crelnumber;
        }
        else
        {
            cout << "Illegal phone number" << endl;
        }
    }
    delete[] num;
    return 0;
}