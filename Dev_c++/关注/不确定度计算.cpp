//��ȷ���ȼ��� 
#include<stdio.h>
#include<math.h>
int main()//�����������ݣ��ûس��ָ���
{
	int digit = 6; 
	double a[digit],Sum1;
	for(int i = 0;i < digit;i ++)										//���ݴ���һ�������� 
	{
		printf("a[%d]=",i);
		scanf("%lf",&a[i]);
		Sum1 += a[i];													//������� 
	}
	double average;
	average = Sum1 / digit;												//������ƽ�� 
	printf("ƽ������%.6f\n",average);
	
	
	
	double Sum2;
	for(int i = 0;i < digit;i ++)
	{
		Sum2 += pow(average - a[i],2);
	}
	double uncertainty1;
	uncertainty1 = sqrt(Sum2 / (digit * (digit - 1)));					//������A�಻ȷ���� 
	printf("A�಻ȷ���ȣ�%.6f\n",uncertainty1);
	
	
	
	double uncertainty2,error;											//��B�಻ȷ����׼�� 
	printf("����������");
	scanf("%lf",&error);
	uncertainty2 = error / sqrt(3);										//���������B�಻ȷ���� 
	printf("B�಻ȷ���ȣ�%.6f\n",uncertainty2); 
	
	
	
	double uncertainty3;												//�ϳɲ�ȷ����׼�� 
	uncertainty3 = sqrt(pow(uncertainty1,2) + pow(uncertainty2,2));
	printf("�ϳɲ�ȷ���ȣ�%.6f\n",uncertainty3);
	
	
	
	double uncertainty4;												//��Բ�ȷ����׼��
	uncertainty4 = uncertainty3 / average;								//������Բ�ȷ���� 
	printf("��Բ�ȷ���ȣ�%.6f\n",uncertainty4); 
	
	
	
	return 0;
} 
