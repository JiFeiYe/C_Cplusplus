#include<stdio.h>
#include<math.h> 							//������ѧ������ͷ�ļ��������·�pow�� 
int main()
{
	printf("������һ����λ������"); 		//��ʾ�� 
	int i;
	scanf("%d",&i);
	if(i<100)								//�ж�����ֵ�Ƿ�Ϊ��λ�� 
	{
		printf("Invalid Value.");
	}
	else if(i>999)
	{
		printf("Invalid Value.");
	}
	else									//���� 
	{
		int j,k,l;							//����λ����λ��������� 
		j = i%10;							//��λ 
		k = i%100/10;						//ʮλ 
		l = i/100; 							//��λ 
		if(i==pow(l,3)+pow(k,3)+pow(j,3))	//�ж����������������ݺ�����Ƿ����ԭ�� 
		{
			printf("Yes");					//��������Yes 
		}
		else
		{
			printf("No");					//����������No 
		}
	}
	return 0;
}
