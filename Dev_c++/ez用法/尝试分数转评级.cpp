//���Է���ת���� 
#include<stdio.h>
int main()
{
	int grade,iSwitch;
	printf("��������ķ�����\n");
	scanf("%d",&grade); 
	if(0 <= grade && grade<100)			//�ڷ���������(0,100]ʱ�����һ����ѭ�� 
	{
		printf("�������Ϊ��");
		iSwitch = grade % 10;			//ͨ�����ʽΪswitch��· 
		switch(iSwitch)
		{
			case 10: 
			case 9:
				printf("A");
				break;
			case 8:
				printf("B");
				break;
			case 7:
				printf("C");
				break;
			case 6:
				printf("D");
				break;
			case 5:
			case 4:
			case 3:
			case 2:
			case 0:
				printf("E");
				break;
			default:
				break;
		}
	}
	else if(grade == 100)				//���ʽ�޷�����100��ֱ���¼ӷ�֧���� 
	{
		printf("�������Ϊ��A\n");
	}
	else 								//�������ݲ����򲻽��м��� 
	{
		printf("�ⲻ����Ҫ����ֵ��\n");
	}
	return 0; 
}
