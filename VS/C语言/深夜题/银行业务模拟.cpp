/*
#include<stdio.h>
int main() {
	int n, t;
	int flag1 = 0;
	int min = 0;//如果一次性有很多人离开窗口时  记录下此时最小的窗口的编号，让下一个顾客L去这个最小的窗口
	scanf("%d %d", &n, &t);//有n个窗口，t个客户。
	int a[n];
	if (n == 0) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	int No;
	int tmp = 0;//打擂台法找到min 先让第一个出来的顾客刚刚所在的窗口编号为tmp 让他为min，以便于后面min与tmp1比较。tmp1和tmp都是来记录顾客离开时窗口编号
	char c, blank;
	int flag = 1;//上一次是L还是S
	int cnt = 0;//记下此时窗口被使用的数量，以便输入0时查询。
	int temp = 0;//临时变量temp，用来a[temp]=No;用来记录窗口号（temp）服务的顾客的编号，以便于后来他离开时输出他所在的窗口编号，银行空荡荡是另temp=0；重新开始计
	int tmp1 = 0;
	for (int i = 0; i < 2 * t; i++) {
		scanf("%d", &No);
		if (No == 0) {
			if (cnt == 0) {
				printf("银行空荡荡~~~\n");
				temp = 0;
				flag = 1;
			}
			if (cnt != 0) {
				printf("现在有%d个窗口有顾客在办理业务\n", cnt);
			}
		}
		else {
			scanf("%c %c", &blank, &c);
			if (cnt == n && c != 'S') {
				printf("Error!\n");
				return 0;
			}
			if (No != 0 && c == 'L') {
				flag1 = 0;
				cnt++;
				if (flag == 1) {
					a[temp] = No;
					temp++;
				}
				if (flag == 0) {
					a[min] = No;
					flag = 1;
					tmp = 0;
					min = 0;
				}
			}
			if (No != 0 && c == 'S') {
				flag1++;
				flag = 0;
				cnt--;
				if (flag1 == 1) {
					for (int k = 0; k < n; k++) {
						if (a[k] == No) {
							tmp = k;
							a[k] = 0;
							break;
						}
					}
					min = tmp;
					printf("顾客编号:%d 窗口编号:%d\n", No, tmp);
				}
				else if (flag1 > 1) {
					for (int k = 0; k < n; k++) {
						if (a[k] == No) {
							tmp1 = k;
							a[k] = 0;
							break;
						}
					}
					if (tmp1 <= min) {
						min = tmp1;
					}
					printf("顾客编号:%d 窗口编号:%d\n", No, tmp1);
				}
			}
		}
	}
	return 0;
}
*/