/// demo 2:通过分隔符来分隔字符串demo
#define _CRT_SECURE_NO_WARNINGS /// 使用类scanf printf这样的函数需要在第一行包含该语句
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
int main()
{
    char *temp = NULL;
    char input[128] = "wifi?ssid=test&passwd=12345678&netmask=255.255.255.0&gateway=192.168.1.1";
    printf("%s\n", input);
    temp = strtok(input, "?"); ////strtok的第一个参数不能为指向常量的指针，我们使用字符数组就好
    printf("input=%s,temp=%s\n", input, temp);
    while (temp != NULL)
    {
        temp = strtok(NULL, "?=&"); ////分隔符为字符串时，则其中的每个字符都是分隔符
        printf("input=%s,temp=%s\n", input, temp);
    };
    return 0;
}

/////unsigned int strlen(char* s)获取字符串长度  头文件string.h
