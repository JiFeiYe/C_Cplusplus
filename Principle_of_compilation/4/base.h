#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct Proce
{                    // 用结构体数组来存放产生式
    char Left;       // 存放产生式的左部
    char Right[100]; // 存放产生式的右部
};
struct Myset
{
    char VN;      // 用于存放FIRSTVT(P)的非终结符
    char VT[100]; // 用于存放FIRSTVT(P)的终结符
};
class Base
{
public:
    int flag;
    struct Proce pro[100];     // 产生式
    struct Myset firstop[100]; // firstvt集合
public:
    Base() : flag(0)
    {
        memset(firstop, 0, sizeof(firstop)); // 置空字符串
        memset(pro, 0, sizeof(pro));
    }
    int is_VN(char ch);                                     // 判断是否是非终结符，默认大写字母为非终结符，其他为终结符
    void is_gram(Proce pro[], int length);                  // 判断文法是否为算符文法
    void NoAdd(Myset VNT[], int length1);                   // 去掉集合中重复部分
    void FIRSTOP(Proce pro[], Myset firstop[], int length); // 求各非终结符的FIRSTVT集合
};
#endif
