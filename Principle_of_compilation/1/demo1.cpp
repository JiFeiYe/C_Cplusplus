// demo 1   文件输入：文件操作的读取
#define _CRT_SECURE_NO_WARNINGS /// 使用类scanf printf这样的函数需要在第一行包含该语句
#define BUFLEN 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lineBuf[BUFLEN];
char V[20], T[20];

int judge() // 判断字符是否对应出现，否则报错
{
    int len = strlen(lineBuf);
    int i = 0;
    int flag2[BUFLEN] = {0};
    for (i = 0; i < len; i++) // line3字符串遍历
    {
        int flag = 0;
        if (lineBuf[i] != '-' && lineBuf[i] != '>' && lineBuf[i] != ',' && lineBuf[i] != '|' && lineBuf[i] != '*')
        {
            int len1 = strlen(V);
            int len2 = strlen(T);
            if (lineBuf[i] >= 65 && lineBuf[i] <= 90)
            {
                for (int j = 0; j < len1; j++)
                {
                    if (lineBuf[i] == V[j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
            {
                for (int j = 0; j < len2; j++)
                {
                    if (lineBuf[i] == T[j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1)
        {
            flag2[i] = 1;
        }
    }
    for (i = 0; i < len - 1; i++)
    {
        if (lineBuf[i] != '-' && lineBuf[i] != '>' && lineBuf[i] != ',' && lineBuf[i] != '|' && lineBuf[i] != '*' && flag2[i] == 0)
            return -1;
    }
    return 0;
}
int Gr1() // 判断1型文法
{
    int count = 0;
    int i = 0;
    int lflag = 0; // ‘|’判断;
    char l[20] = {0}, r[20] = {0};
    int flag = 0; // 非终结符判断
    while (lineBuf[i] != '\n')
    {
        if (lflag != 1)
        {
            memset(l, 0, 20);
            flag = 0;
        }
        memset(r, 0, 20);
        for (; lineBuf[i] != '-'; i++) // 读入左边
        {
            if (lflag == 1)
            {
                i -= 2;
                lflag = 0;
                break;
            }
            l[strlen(l)] = lineBuf[i];
            if (lineBuf[i] >= 65 && lineBuf[i] <= 90)
                flag = 1; // 包含一个非终结符
        }
        i += 2;
        for (; lineBuf[i] != ','; i++) // 读入右边
        {
            if (lineBuf[i] == '|')
            {
                lflag = 1;
                break;
            }
            r[strlen(r)] = lineBuf[i];
            if (lineBuf[i + 1] == '\n')
                break;
        }
        i++;
        if ((strlen(l) <= strlen(r) && flag == 1) || r[0] == '*')
        {
            count = 1; // 符合1型文法
        }
        else
        {
            count = 0; // 不符合1型文法
            break;
        }
    }
    return count;
}
int Gr2() // 判断2型文法
{
    int count = 1;
    int i = 0;
    int lflag = 0; // ‘|’判断
    char l[20] = {0}, r[20] = {0};
    int flag = 0;
    while (lineBuf[i] != '\n')
    {
        if (lflag != 1)
        {
            memset(l, 0, 20);
            flag = 0;
        }
        memset(r, 0, 20);
        for (; lineBuf[i] != '-'; i++)
        {
            if (lflag == 1)
            {
                i -= 2;
                lflag = 0;
                break;
            }
            l[strlen(l)] = lineBuf[i];
            if (lineBuf[i] >= 65 && lineBuf[i] <= 90)
                flag = 1; // 包含一个非终结符
        }
        i += 2;
        for (; lineBuf[i] != ','; i++)
        {
            if (lineBuf[i] == '|')
            {
                lflag = 1;
                break;
            }
            r[strlen(r)] = lineBuf[i];
            if (lineBuf[i + 1] == '\n')
                break;
        }
        i++;
        if ((strlen(l) == 1 && flag == 1) || r[0] == '*')
            count = 2;
        else
        {
            count = 1;
            break;
        }
    }
    return count;
}
int rlflag = -1; // 初始-1，左线性1，右线性2，均可且优先0，错误3
int Gr3()        // 判断3型文法
{
    int count = 2;
    int i = 0;
    while (lineBuf[i] != '\n')
    {
        char r[20] = {0};
        i += 3;
        for (; lineBuf[i] != ','; i++)
        {
            if (lineBuf[i] == '|')
            {
                i -= 3;
                break;
            }
            r[strlen(r)] = lineBuf[i];
            if (lineBuf[i + 1] == '\n')
                break;
        }
        i++;
        int j = strlen(r);
        if (r[0] == '*')
            continue;
        for (int k = 1; k < j - 1; k++)
        {
            if (r[k] >= 65 && r[k] <= 90)
                return 2;
        }
        if (!(r[0] >= 65 && r[0] <= 90) && !(r[j - 1] >= 65 && r[j - 1] <= 90))
        {
            count = 3;
            continue;
        }
        if (j == 1 && (r[0] >= 65 && r[0] <= 90)) // 长度1还大写
            rlflag = 3;
        else if (j == 1 && !(r[0] >= 65 && r[0] <= 90))
            rlflag = rlflag;
        else if (rlflag <= 1 && r[0] >= 65 && r[0] <= 90)
            rlflag = 1;
        else if ((rlflag == -1 || rlflag == 0 || rlflag == 2) && r[j - 1] >= 65 && r[j - 1] <= 90)
            rlflag = 2;
        else
            rlflag = 3;

        if (rlflag < 3)
            count = 3;
        else
        {
            count = 2;
            break;
        }
    }
    return count;
}

int main()
{
    FILE *source;
    const char *pgm = "D:\\CODE\\Visual_Studio_Code_Principle_of_compilation\\23.3.23\\Grammar.txt";
    source = fopen(pgm, "rw"); // 获得文件指针
    int line = 1;              // 当前语句第1234行
    int count = 0;             // 0123型文法,默认0型
    while (1)
    {
        if (fgets(lineBuf, BUFLEN - 1, source))
        { /// 逐行读入文件内容，每次读入的内容都存放在lineBuf中
            // 这里按照乔姆斯基的分类分析每行内容
            if (lineBuf[0] == '\n') // 下一段文法内容,初始化内容
            {
                line = 0;
                count = 0;
                rlflag = -1;
                memset(lineBuf, 0, BUFLEN);
                memset(V, 0, 20);
                memset(T, 0, 20);
            }
            if (line == 3)
            {
                if (judge() == -1)
                    return -1; // 主函数返回-1报错
                // 判断方法(一次算完)
                if (count == 0)
                    count = Gr1();
                if (count == 1)
                    count = Gr2();
                if (count == 2)
                    count = Gr3();
                printf("%d型文法\n", count);
                line++;
            }
            else
            {
                if (line == 1)
                {
                    for (int i = 0; lineBuf[i] != '\n'; i++)
                    {
                        if (lineBuf[i] != ',')
                            V[strlen(V)] = lineBuf[i];
                    }
                }
                else if (line == 2)
                {
                    for (int i = 0; lineBuf[i] != '\n'; i++)
                    {
                        if (lineBuf[i] != ',')
                            T[strlen(T)] = lineBuf[i];
                    }
                }
                line++;
            }
        }
        else
        { ////已经到了文件末尾，可以直接退出
            ////end of file
            break;
        }
    }
    fclose(source); /// 用完后要关闭文件指针
    return 0;
}