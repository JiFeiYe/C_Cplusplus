/*
#include<stdio.h>

int choice(int year, int month) {
	int days = 0;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		switch (month) {
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
			case 4:case 6:case 9:case 11:return 30;
			case 2:return 29;
		}
	}
	else {
		switch (month) {
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
			case 4:case 6:case 9:case 11:return 30;
			case 2: return 28;
		}
	}
}
int main() {
	int year = 0, month = 0, days = 0;
	scanf_s("%d%d", &year, &month);//输入月份没啥用？
	for (int i = 1; i <= 12; i++) {
		
		printf("%d ", choice(year, i));
	}
	return 0;
}
*/