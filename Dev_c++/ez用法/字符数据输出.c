#include<stdio.h>
int main()
{
	char a;
	a = getchar();			//�������豸���õ��ַ� 
	putchar(a);				//�����������'' 
	putchar('\n');			//���ת���ַ� 
	
	getchar();				//�õ��س��ַ���ע�⣩ 
	
	putchar(getchar());		//�õ������ַ�ֱ������� 
	putchar('\n'); 
	
	return 0;
}
