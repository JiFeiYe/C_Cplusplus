#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
    CDate() = default;
	CDate(int y_, int m_, int d_);
	bool check(); //检验日期是否合法
	bool isLeap();
	void print();
    int gety(){return year;}
    int getm(){return month;}
    int getd(){return day;}
};
CDate::CDate(int y_, int m_, int d_)
{
    year = y_; month = m_; day = d_;
}
bool CDate::check()
{
    if(month > 12 || month < 0)
    {
        return 0;
    }
    int month1[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    if(year %4 == 0 && year% 100 != 0 || year% 400 == 0)//是闰年
    {
        month1[2]++;
    }
    if(day > month1[month])
    {
        return 0;
    }
    return 1;
}
void CDate::print()
{
    cout << year << "年" << month << "月" << day << "日";
    return;
}

class COldId
{
protected:
	char* pId15, * pName; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldId(char* pIdVal, char* pNameVal, CDate& day);
	void print();
	~COldId();
};
COldId::COldId(char* pIdVal, char* pNameVal, CDate& day)
{
    pId15 = new char[16];
    pName = new char[21];
    strcpy(pId15, pIdVal); strcpy(pName, pNameVal); birthday = day;
}
COldId::~COldId()
{
    delete[] pId15;
    delete[] pName;
}

class CNewId:public COldId
{
private:
    char pId18[19];
    CDate issueDay;
    int validYear;
public:
    CNewId(char* pIdVal, char* pNameVal, CDate& day, char* pId18_, CDate& issueDay_, int validYear_): COldId(pIdVal, pNameVal, day)
    {
        strcpy(pId18, pId18_); issueDay = issueDay_; validYear = validYear_;
    }
	bool check();
    void print();
    char* getname()
    {
        return pName;
    }
};
bool CNewId::check()
{   
    if(birthday.check() && issueDay.check()){}
    else{return false;}
    int tyear = pId18[9]-48 + (pId18[8]-48)*10 + (pId18[7]-48)*100 + (pId18[6]-48)*1000;
    int tmonth = pId18[11]-48 + (pId18[10]-48)*10;
    int tday = pId18[13]-48 + (pId18[12]-48)*10;
    if(tyear != birthday.gety() || tmonth != birthday.getm() || tday != birthday.getd()){return false;}
    int flag_ = 0;
    for(int i = 0; i < 6; i++)
    {
        if(pId15[i] == pId18[i]){}
        else{flag_ = 1;}
    }
    for(int i = 8; i < 17; i++)
    {
        if(pId15[i-2] == pId18[i]){}
        else{flag_ = 1;}
    }
    if(flag_ == 0)
    {
        int temp = 0;//7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2
        temp = 
        (pId18[0]-48)*7 + (pId18[1]-48)*9 + (pId18[2]-48)*10 + (pId18[3]-48)*5
        + (pId18[4]-48)*8 + (pId18[5]-48)*4 + (pId18[6]-48)*2 + (pId18[7]-48)*1
        + (pId18[8]-48)*6 + (pId18[9]-48)*3 + (pId18[10]-48)*7 + (pId18[11]-48)*9
        + (pId18[12]-48)*10 + (pId18[13]-48)*5 + (pId18[14]-48)*8 + (pId18[15]-48)*4
        + (pId18[16]-48)*2;
        temp = temp % 11;
        char temp1 = ' ';
        switch(temp)//1,0,X,9,8,7,6,5,4,3,2
        {
            case 0: temp1 = '1'; break;
            case 1: temp1 = '0'; break;
            case 2: temp1 = 'X'; break;
            case 3: temp1 = '9'; break;
            case 4: temp1 = '8'; break;
            case 5: temp1 = '7'; break;
            case 6: temp1 = '6'; break;
            case 7: temp1 = '5'; break;
            case 8: temp1 = '4'; break;
            case 9: temp1 = '3'; break;
            case 10: temp1 = '2'; break;
        }
        if(temp1 == pId18[17])//校验位正确
        {
            if(strlen(pId18) == 18)//长度18
            {
                int flag = 0;
                for(int i = 0; i < 17; i++)
                {
                    if(pId18[i] >= '0' && pId18[i] <= '9')
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                        return false;
                    }
                }
                if(flag == 0)
                {
                    if(pId18[17] >= '0' && pId18[17] <= '9' || pId18[17] == 'X')//不含非法字符
                    {
                        if(birthday.gety() < 2021)//生日无误
                        {
                            if(issueDay.gety()+validYear > 2021)//有效期内
                            {
                                
                                return true;
                            }
                            else if(validYear == 100)
                            {
                                
                                return true;
                            }
                            else if(issueDay.gety()+validYear == 2021 && issueDay.getm() > 11)
                            {
                                
                                return true;
                            }
                            else if(issueDay.gety()+validYear == 2021 && issueDay.getm() == 11 && issueDay.getd() >= 8)
                            {
                                
                                return true;
                            }
                            else{return false;}
                        }
                        else if(birthday.gety() == 2021 && birthday.getm() < 11)
                        {
                            if(issueDay.gety()+validYear > 2021)//有效期内
                            {
                                
                                return true;
                            }
                            else if(validYear == 100)
                            {
                                
                                return true;
                            }
                            else if(issueDay.gety()+validYear == 2021 && issueDay.getm() > 11)
                            {
                                
                                return true;
                            }
                            else if(issueDay.gety()+validYear == 2021 && issueDay.getm() == 11 && issueDay.getd() >= 8)
                            {
                                
                                return true;
                            }
                            else{return false;}
                        }
                        else if(birthday.gety() == 2021 && birthday.getm() == 11 && birthday.getd() <= 8)
                        {
                            if(issueDay.gety()+validYear > 2021)//有效期内
                            {
                                
                                return true;
                            }
                            else if(validYear == 100)
                            {
                                
                                return true;
                            }
                            else if(issueDay.gety()+validYear == 2021 && issueDay.getm() > 11)
                            {
                                
                                return true;
                            }
                            else if(issueDay.gety()+validYear == 2021 && issueDay.getm() == 11 && issueDay.getd() >= 8)
                            {
                                
                                return true;
                            }else{return false;}
                        }else{return false;}
                    }else{return false;}
                }else{return false;}
            }else{return false;}
        }else{return false;}
    }else{return false;}
}
void CNewId::print()
{
    cout << pName << endl;
    cout << pId18 << " " ;
    issueDay.print(); 
    if(validYear != 100)
    {
        cout << " " << validYear << "年" << endl;
    }
    else
    {
        cout << " 长期" << endl;
    }
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    char name[21];
    int year = 0, month = 0, day = 0;
    char id15[16] = {' '}, id18[19] = {' '};
    int issyear = 0, issmonth = 0, issday = 0;
    int validyear = 0;
    while(t--)
    {
        cin >> name >> year >> month >> day >> id15 >> id18 >> issyear >> issmonth >> issday >> validyear;
        CDate birthday(year, month, day);
        CDate issueDay(issyear, issmonth, issday);
        CNewId newid(id15, name, birthday, id18, issueDay, validyear);
        if(newid.check())
        {
            newid.print();
        }
        else
        {
            cout << newid.getname() << endl;
            cout << "illegal id" << endl;
        }
    }
    return 0;
}