/*
#include<stdio.h>
int main() {
	int n, t;
	int flag1 = 0;
	int min = 0;//���һ�����кܶ����뿪����ʱ  ��¼�´�ʱ��С�Ĵ��ڵı�ţ�����һ���˿�Lȥ�����С�Ĵ���
	scanf("%d %d", &n, &t);//��n�����ڣ�t���ͻ���
	int a[n];
	if (n == 0) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	int No;
	int tmp = 0;//����̨���ҵ�min ���õ�һ�������Ĺ˿͸ո����ڵĴ��ڱ��Ϊtmp ����Ϊmin���Ա��ں���min��tmp1�Ƚϡ�tmp1��tmp��������¼�˿��뿪ʱ���ڱ��
	char c, blank;
	int flag = 1;//��һ����L����S
	int cnt = 0;//���´�ʱ���ڱ�ʹ�õ��������Ա�����0ʱ��ѯ��
	int temp = 0;//��ʱ����temp������a[temp]=No;������¼���ںţ�temp������Ĺ˿͵ı�ţ��Ա��ں������뿪ʱ��������ڵĴ��ڱ�ţ����пյ�������temp=0�����¿�ʼ��
	int tmp1 = 0;
	for (int i = 0; i < 2 * t; i++) {
		scanf("%d", &No);
		if (No == 0) {
			if (cnt == 0) {
				printf("���пյ���~~~\n");
				temp = 0;
				flag = 1;
			}
			if (cnt != 0) {
				printf("������%d�������й˿��ڰ���ҵ��\n", cnt);
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
					printf("�˿ͱ��:%d ���ڱ��:%d\n", No, tmp);
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
					printf("�˿ͱ��:%d ���ڱ��:%d\n", No, tmp1);
				}
			}
		}
	}
	return 0;
}
*/