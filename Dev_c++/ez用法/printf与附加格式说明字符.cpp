#include<stdio.h>
int main()
{
	long long i=999999;
	printf("The Long is:%ld\n",i);			//��ĸl��ʾ��������ͱ���������d��ʹ�� 
	
	printf("That is:%s\n","Love");			//s��ʾ����ַ����������ַ�����""
	printf("That is:%9s\n","Love");			//%������ֱ�ʾ�ո���
	printf("That is:%-9s\n","Love");		//%�󸺺ű�ʾ���󿿣�������ո� 
	printf("That is:%9.3s\n","Love");		//.3��ʾȡ�ַ�����ǰ��λ��������ո�ʵ������ȡС�������λ 
	printf("That is:%-9.3s\n","Love");		//ȡǰ��λ������ 
	return 0;
 }
