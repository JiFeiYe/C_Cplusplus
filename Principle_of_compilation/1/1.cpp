#include<stdio.h>
#include<string.h>

int main()
{
    char ch[] = {"fdsajxkflaf"};
    char sh[20] = {"Dsafef"};
    for(int i = 0 ; i < 5; i++)
    {
        sh[strlen(sh)] = ch[i];
    }
    
    return 0;
}