#include"head.h"

char chess[3][3] = {' '};//一个灵魂：静态全局变量chess，用于棋子功能
char count1[3][3] = { 0 };//计数数组将于棋子数组同步，用于实现“下第四子时移除第一子”功能  
int flag = 0;//1:A  0:B\电脑

int main()
{
	ShowMenu();//打印首页与菜单
	ChooseMode();//模式选择
	return 0;
}

//菜单打印	
void ShowMenu()
{
	printf("\n\n\n");
	printf("                              井字棋\n");
	printf("                    Express any key to continue\n");//这句话的及其后续实现功能可以直接用system("pause");来代替
	while (1)
	{
		if (_kbhit())//判断是否有按键被按下
		{
			_getch();//读取缓冲区
			system("cls");//刷新界面
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

//选择模式
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

//人机对战
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
		printf("Please choose one of the coordinates of the blank space : ");//coordinate:坐标
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
		//下子+判断四子
		if (flag == 1)
		{
			scanf_s("%d%d", &i, &j);
			fflush(stdin);//清空缓冲区
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
		else if (flag == 0)//机器部分
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
		//输赢判断
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
		flag = -flag + 1;//AB换人
		//达到四子操作
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

//好友对战
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
		printf("Please choose one of the coordinates of the blank space : ");//coordinate:坐标
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
		fflush(stdin);//清空缓冲区
		//下子+判断四子
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
		//输赢判断
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
		flag = -flag + 1;//AB换人
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

//机器挑子
void ComputerAct()
{
	int i = 0, j = 0;
	srand((unsigned)time(0));//设置随机数种子
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

//输赢平判断
char WinorLose()
{
	for (int i = 0; i < 2; i++) //判断行
	{
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][2] != '\0')
		{
			return chess[i][0];
		}
	}
	for (int i = 0; i < 2; i++)	//判断列
	{
		if (chess[0][i] == chess[1][i] && chess[1][i] == chess[2][i] && chess[2][i] != '\0')
		{
			return chess[0][i];
		}
	}
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][2] != '\0')//判断对角线
	{
		return chess[0][0];
	}
	if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0] && chess[2][0] != '\0')
	{
		return chess[0][2];
	}
	return ' ';
}

//先手权选择（随机数）
void WhoFirst()//玩家A 与 玩家B\电脑
{
	int random = 0;
	srand((unsigned)time(0));//设置随机数种子
	random = rand() % 100;//0~99
	if (random < 50)//小于50
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	return;
}

//棋盘打印
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
