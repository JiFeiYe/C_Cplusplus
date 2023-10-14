//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//class CDate
//{
//private:
//	int year, month, day;
//public:
//	CDate(int y, int m, int d) {
//		year = y;
//		month = m;
//		day = d;
//	}
//	bool check() {
//		int flag;
//		flag = isLeap();
//		int monthday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (flag == 1) {
//			monthday[1] = { 29 };
//		}
//		else {
//			
//		}
//		if (day<0 || year < 0 || month < 0 || year>2021 || month>12 || day> monthday[month - 1]) {
//			cout << "1" << endl;
//			return 0;//判断闰年日期合理性
//		}
//		else {
//			return 1;
//		}
//
//	}//检验日期是否合法
//	bool isLeap() {
//		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//	int getyear() { return year; }
//	int getmonth() { return month; }
//	int getday() { return day; }
//	void print() {
//		cout << year << "年" << month << "月" << day << "日";
//	}
//};
//
//class COldId
//{
//protected:
//	char* pId15, * pName; //15位身份证号码，姓名
//	CDate birthday; //出生日期
//public:
//	COldId(char* pIdVal, char* pNameVal, int y, int m, int d) :birthday(y, m, d) {
//		pId15 = new char[strlen(pIdVal) + 1];
//		strcpy(pId15, pIdVal);
//		pName = new char[21];
//		//pNameVal = new char[strlen(pNameVal) + 1];
//		strcpy(pName, pNameVal);
//	}
//	int check() {
//		//1
//		if (strlen(pId15) != 15) { cout << "2" << endl; return 0; }
//		//2
//		for (int i = 0; i < 15; i++) {
//			if ('0' > *(pId15 + i) || *(pId15 + i) >= '9') {
//				cout << "3" << endl;
//				return 0;
//			}
//		}
//		//3
//		if (birthday.check() == 0) { cout << "4" << endl;  return 0; }
//		//4
//		if ((*(pId15 + 6) - '0') * 10 + (*(pId15 + 7) - '0') != birthday.getyear()%100 || (*(pId15 + 8) - '0') * 10 + (*(pId15 + 9) - '0') != birthday.getmonth() || (*(pId15 + 10) - '0') * 10 + (*(pId15 + 11) - '0') != birthday.getday()) {
//			cout << "5" << endl;
//			return 0;
//		}
//		return 1;
//	} //验证15位身份证是否合法
//	void print() {
//		cout << pName << endl;
//	}
//	~COldId() {}
//};
//class CNewId :virtual public COldId {
//private:
//	char* pId18;
//	CDate issueDay;
//	int validYear;
//public:
//	CNewId(char* _pId18, char* pIdVal, char* pNameVal, int y, int m, int d, int y1, int m1, int d1, int _validYear) :COldId(pIdVal, pNameVal, y, m, d), issueDay(y1, m1, d1), validYear(_validYear) {
//		pId18 = new char[strlen(_pId18) + 1];
//		strcpy(pId18, _pId18);
//	}
//	char* newnumID() { //返回地址，设立static.
//		static char num[20];
//		for (int i = 0; i < 6; i++) {
//			num[i] = *(pId15 + i);
//		}
//		if (birthday.getyear() < 2000) {
//			num[6] = '1';
//			num[7] = '9';
//		}
//		else {
//			num[6] = '2';
//			num[7] = '0';
//		}
//		for (int i = 8; i < 17; i++) {
//			num[i] = *(pId15 + i - 2);
//		}
//		//处理第18位。
//		int list1[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//		char list2[] = { '1','0','X','9','8','7','6','5','4','3','2','\0' };
//		int sum = 0;
//		for (int i = 0; i < 17; i++) {
//			sum += ((num[i] - '0') * list1[i]);
//		}
//		sum = sum % 11;
//		num[17] = list2[sum];
//		num[18] = '\0';
//		return num;
//	}
//	bool check() {
//		int flag = 0;
//		if ((issueDay.getyear() + validYear) > 2021 || (issueDay.getyear() + validYear) == 2021 && issueDay.getmonth() < 11 || (issueDay.getyear() + validYear) == 2021 && issueDay.getmonth() == 11 && issueDay.getday() < 8) {
//			flag = 1;
//		}
//		else {
//			flag = 0;
//		}
//		if (strcmp(newnumID(), pId18) != 0 || issueDay.check() == 0 || flag == 0) {
//			return 0;
//		}
//		else {
//			return 1;
//		}
//	}
//	void print() {
//		cout << pId18 << " ";
//		issueDay.print();
//		if (validYear != 100) {
//			cout << " " << validYear << "年" << endl;
//		}
//		else {
//			cout << "长期" << endl;
//		}
//	}
//	~CNewId() {}
//};
//int main() {
//	int t;
//	cin >> t;
//	int y1, m1, d1;
//	int y2, m2, d2;
//	int v;
//	char name[20], p15[20], p18[20];
//	for (int k = 0; k < t; k++) {
//		cin >> name >> y1 >> m1 >> d1 >> p15 >> p18 >> y2 >> m2 >> d2 >> v;
//		CNewId c(p18, p15, name, y1, m1, d1, y2, m2, d2, v);
//		c.COldId::print();
//		if (c.COldId::check() && c.check()) {
//			c.print();
//		}
//		else {
//			cout << "illegal id" << endl;
//		}
//	}
//	return 0;
//}