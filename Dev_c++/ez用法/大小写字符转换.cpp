#include<stdio.h>
int main()
{
	char cBig;
	char cSmall;
	
	puts("������һ����д��ĸ��");			

	cBig = getchar();
	cSmall = cBig+32;						//����ASCII��ת���ַ� 
	
	puts("��ӦСд��ĸΪ��");
	putchar(cSmall);
	return 0; 
}
