#include<stdio.h>
int main()
{
	long i;							//���峤���ͱ��� 
	short j;						//��������ͱ��� 
	int k1 = 1;						//�������ͱ��� 
	int k2 = 2;
	char l[10];						//�����ַ��������
	
	printf("Long:\n");
	scanf("%ld",&i);				//���볤�������ݣ�l�� 
	
	printf("Short:\n");
	scanf("%hd",&j);				//������������ݣ�h�� 
	
	printf("Number:\n");
	scanf("%d*%d",&k1,&k2);			//�����������ݣ�*��ʾ���Եڶ�������ֵ����k2���ᱻ���¸�ֵ 
	
	printf("String:\n");
	scanf("%5s",l);					//�����ַ�����5��ʾ������ռ��ȣ����������ݹ�����ȡǰ��λ 
	
	printf("Long is:%ld\n",i);
	printf("Short is:%hd\n",j);
	printf("Number1 is:%d\n",k1);
	printf("Number2 is:%d\n",k2);
	printf("String is:%s\n",l);
	
	return 0;
}
