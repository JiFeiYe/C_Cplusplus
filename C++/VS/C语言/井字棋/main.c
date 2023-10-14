#include"head.h"

char chess[3][3] = {' '};//һ����꣺��̬ȫ�ֱ���chess���������ӹ���
char count1[3][3] = { 0 };//�������齫����������ͬ��������ʵ�֡��µ�����ʱ�Ƴ���һ�ӡ�����  
int flag = 0;//1:A  0:B\����

int main()
{
	ShowMenu();//��ӡ��ҳ��˵�
	ChooseMode();//ģʽѡ��
	return 0;
}

//�˵���ӡ	
void ShowMenu()
{
	printf("\n\n\n");
	printf("                              ������\n");
	printf("                    Express any key to continue\n");//��仰�ļ������ʵ�ֹ��ܿ���ֱ����system("pause");������
	while (1)
	{
		if (_kbhit())//�ж��Ƿ��а���������
		{
			_getch();//��ȡ������
			system("cls");//ˢ�½���
			break;
		}
	}
	printf("//////////////////////////////////////////////////////////////////////\n");
	printf("/////////                       MENU                        //////////\n");
	printf("/////////   please enter the number to choose game mode     //////////\n");
	printf("/////////               Play with computer:1                //////////\n");
	printf("/////////                Play with friend:2                 //////////\n");
	printf("/////////                       or                          //////////\n");
	printf("/////////                     Exit:0                        //////////\n");
	printf("//////////////////////////////////////////////////////////////////////\n");
	return;
}

//ѡ��ģʽ
void ChooseMode()
{
	int input = 0;
	while (1)
	{
		scanf_s("%d", &input);
		if (input == 1)
		{
			system("cls");
			WithComputer();
			break;
		}
		else if (input == 2)
		{
			system("cls");
			WithFriend();
			break;
		}
		else if (input == 0)
		{
			system("cls");
			printf("See you.\n");
			return ;
		}
	}
	return;
}

//�˻���ս
void WithComputer()
{
	ShowBorad();
	int temp = 1;
	if (temp == 1)
	{
		WhoFirst();
	}
	if (flag == 1 && temp == 1)
	{
		printf("Player A first!\n");
		printf("Please choose one of the coordinates of the blank space : ");//coordinate:����
	}
	else if (flag == 0 && temp == 1)
	{
		printf("Player B first!\n");
		printf("Please choose one of the coordinates of the blank space : ");
	}
	while (1)
	{
		if (flag == 1 && temp == 0)
		{
			printf("It's A turn.\nPlease choose one of the coordinates of the blank space: ");

		}
		else if (flag == 0 && temp == 0)
		{
			printf("It's B turn.\nPlease choose one of the coordinates of the blank space: ");
		}
		temp = 0;
		int i = 0, j = 0;
		//����+�ж�����
		if (flag == 1)
		{
			scanf_s("%d%d", &i, &j);
			fflush(stdin);//��ջ�����
			chess[i][j] = 'A';
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (count1[k][l] != 0)
						count1[k][l]--;
				}
			}
			count1[i][j] = 6;
		}
		else if (flag == 0)//��������
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (count1[k][l] != 0)
						count1[k][l]--;
				}
			}
			ComputerAct();
		}
		ShowBorad();
		//��Ӯ�ж�
		char temp1 = { 0 };
		temp1 = WinorLose();
		if (temp1 == 'A')
		{
			printf("A win! \n");
			break;
		}
		else if (temp1 == 'B')
		{
			printf("B win!\n");
			break;
		}
		flag = -flag + 1;//AB����
		//�ﵽ���Ӳ���
		for (int k = 0; k < 3; k++)
		{
			for (int l = 0; l < 3; l++)
			{
				if (count1[k][l] == 0)
				{
					chess[k][l] = ' ';
					count1[k][l] = 0;
				}
			}
		}
		ShowBorad();
	}
	return;
}

//���Ѷ�ս
void WithFriend()
{
	int temp = 1;
	if (temp == 1)
	{
		ShowBorad();
		WhoFirst();
	}
	if (flag == 1 && temp == 1)
	{
		printf("Player A first!\n");
		printf("Please choose one of the coordinates of the blank space : ");//coordinate:����
	}
	else if (flag == 0 && temp == 1)
	{
		printf("Player B first!\n");
		printf("Please choose one of the coordinates of the blank space : ");
	}
	while (1)
	{
		if (flag == 1 && temp == 0)
		{
			printf("It's A turn.\nPlease choose one of the coordinates of the blank space: ");
			
		}
		else if (flag == 0 && temp == 0)
		{
			printf("It's B turn.\nPlease choose one of the coordinates of the blank space: ");
		}
		temp = 0;
		int i = 0, j = 0;
		scanf_s("%d%d", &i, &j);
		fflush(stdin);//��ջ�����
		//����+�ж�����
		if (flag == 1)
		{
			chess[i][j] = 'A';
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (count1[k][l] != 0)
						count1[k][l]--;
				}
			}
			count1[i][j] = 6;
		}
		else if (flag == 0)
		{
			chess[i][j] = 'B';
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (count1[k][l] != 0)
						count1[k][l]--;
				}
			}
			count1[i][j] = 6;
		}
		ShowBorad();
		//��Ӯ�ж�
		char temp1 = { ' '};
		temp1 = WinorLose();
		if (temp1 == 'A')
		{
			printf("A win! \n");
			break;
		}
		else if (temp1 == 'B')
		{
			printf("B win!\n");
			break;
		}
		flag = -flag + 1;//AB����
		for (int k = 0; k < 3; k++)
		{
			for (int l = 0; l < 3; l++)
			{
				if (count1[k][l] == 0)
				{
					chess[k][l] = ' ';
					count1[k][l] = 0;
				}
			}
		}
		ShowBorad();
	}
	return;
}

//��������
void ComputerAct()
{
	int i = 0, j = 0;
	srand((unsigned)time(0));//�������������
	do
	{
		i = (rand() % 15) / 5;
		j = (rand() % 15) / 5;
		if (chess[i][j] != 'A' && chess[i][j] != 'B')
		{
			chess[i][j] = 'B';
			count1[i][j] = 6;
			break;
		}
	} while (1);
	return;
}

//��Ӯƽ�ж�
char WinorLose()
{
	for (int i = 0; i < 2; i++) //�ж���
	{
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][2] != '\0')
		{
			return chess[i][0];
		}
	}
	for (int i = 0; i < 2; i++)	//�ж���
	{
		if (chess[0][i] == chess[1][i] && chess[1][i] == chess[2][i] && chess[2][i] != '\0')
		{
			return chess[0][i];
		}
	}
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][2] != '\0')//�ж϶Խ���
	{
		return chess[0][0];
	}
	if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0] && chess[2][0] != '\0')
	{
		return chess[0][2];
	}
	return ' ';
}

//����Ȩѡ���������
void WhoFirst()//���A �� ���B\����
{
	int random = 0;
	srand((unsigned)time(0));//�������������
	random = rand() % 100;//0~99
	if (random < 50)//С��50
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	return;
}

//���̴�ӡ
void ShowBorad()
{
	system("cls");
	printf("Player1:A    Player2:B\n");
	printf("    0   1    2\n");
	printf(" 0  %c  |  %c  | %c\n", chess[0][0], chess[0][1], chess[0][2]);
	printf("   ------------\n");
	printf(" 1  %c  |  %c  | %c\n", chess[1][0], chess[1][1], chess[1][2]);
	printf("   ------------\n");
	printf(" 2  %c  |  %c  | %c\n", chess[2][0], chess[2][1], chess[2][2]);
	return;
}
