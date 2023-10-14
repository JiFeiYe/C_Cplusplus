#include<stdio.h>
int main()
{
	int random,N;
	scanf("%d%d",&random,&N);
	
	int guess,i;
	for(i = 1;i <= N;i ++)
	{
		scanf("%d",&guess);
		if(guess < 0)
		{
			printf("Game Over");
			goto Somewhere;
		}
		if(guess > random)
		{
			printf("Too big\n");
		}
		else if(guess < random)
		{
			printf("Too small\n");
		}
		else
		{
			break;
		}
	}
		if(i == 1 && guess == random)
		{
			printf("Bingo!");
		}
		else if(i > 1 && i <= 3 && guess == random)
		{
			printf("Lucky You!");
		}
		else if(i > 3 && i <= N && guess == random)
		{
			printf("Good Guess!");
		}
		else
		{
			printf("Game Over");
		}
	
Somewhere:
	return 0;
}
