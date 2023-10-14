#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

const int MAX = 300;
char ex[MAX];

int main()
{
    char str[MAX];
    char stack[MAX];
    char ch = ' ';
    int sum, i, j, t, top = 0;
    printf("请输入一个求值的表达式，以#结束。\n");
    printf("算术表达式：");
    i = 0;
    // 输入表达式
    while (str[i++] != '#' && i != MAX)
    {
        scanf("%c", &str[i]); // 不用s是为了获得i
    }

    sum = i;
    t = 1;
    i = 1;
    ch = str[i];
    i++;
    while (ch != '#')
    {
        switch (ch)
        {
        case '(': // 判定为左括号
            top++;
            stack[top] = ch;
            break;
        case ')': // 判定为右括号
            while (stack[top] != '(')
            {
                ex[t] = stack[top];
                top--;
                t++;
            }
            top--;
            break;
        case '+': // 判定为加减号
        case '-':
            while (top != 0 && stack[top] != '(')
            {
                ex[t] = stack[top];
                top--;
                t++;
            }
            top++;
            stack[top] = ch;
            break;
        case '*':
        case '/':
            while (stack[top] == '*' || stack[top] == '/')
            {
                ex[t] = stack[top];
                top--;
                t++;
            }
            top++;
            stack[top] = ch;
            break;
        case ' ':
            break;
        default:
            while ((ch >= '0' && ch <= '9') || ch == '.')
            {
                ex[t] = ch;
                t++;
                ch = str[i];
                i++;
            }
            i--;
            ex[t] = ' ';
            t++;
            break; // 添加break
        }
        ch = str[i];
        i++;
    }
    while (top != 0) // 扫描完毕时检查是否为空，不为空则一一出栈
    {
        ex[t] = stack[top];
        t++;
        top--;
    }
    ex[t] = '#';

    printf("原式：");
    for (j = 1; j < sum; j++)
        printf("%c", str[j]);
    printf("\n");
    printf("逆波兰式：", ex);
    for (j = 1; j < t; j++)
        printf("%c", ex[j]);
    printf("\n");

    float stack1[MAX], d;
    ch = ' ';
    t = 1, top = 0;
    ch = ex[t];
    t++;
    while (ch != '#')
    {
        switch (ch)
        {
        case '+':
            stack1[top - 1] = stack1[top - 1] + stack1[top];
            top--;
            break;
        case '-':
            stack1[top - 1] = stack1[top - 1] - stack1[top];
            top--;
            break;
        case '*':
            stack1[top - 1] = stack1[top - 1] * stack1[top];
            top--;
            break;
        case '/':
            if (stack1[top] != 0)
                stack1[top - 1] = stack1[top - 1] / stack1[top];
            else
            {
                printf("error: 0不可作为除数！\n");
                exit(0);
            }
            top--;
            break;
        default:
            char num[10];
            int index = 0;
            while ((ch >= '0' && ch <= '9') || ch == '.')
            {
                num[index++] = ch;
                ch = ex[t];
                t++;
            }
            num[index] = '\0';
            top++;
            stack1[top] = atof(num); // atof:将str转化为double
        }
        ch = ex[t];
        t++;
    }
    printf("得出:%g\n", stack1[top]);
}
