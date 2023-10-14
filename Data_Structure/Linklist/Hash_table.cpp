#include<iostream>
#include<cstring>
using namespace std;
#define m 15//哈希表表长
#define NULLKEY 0//单元为空的标记

int Hash(int key)//哈希函数
{
    return key%13;
}
int LineDetect(int HT[], int H0, int key, int &cnt)//线性探测法
{
    int Hi;
    for(int i = 1; i < m; i++)
    {
        cnt++;
        Hi = (H0 + i) % m;//按照线性探测法计算下一个哈希地址
        if(HT[Hi] == NULLKEY || HT[Hi] == key)//若单元Hi为空或者查找成功
            return Hi;
    }
    return -1;
}
int SecondDetect(int HT[], int H0, int key, int &cnt)//二次探测
{
    int Hi;
    for(int i = 1; i <= m/2; i++)
    {
        int i1 = i * i;
        int i2 = -i1;
        cnt++;
        Hi = (H0 + i1) % m;//按照二次探测法计算下一个哈希地址
        if(HT[Hi] == NULLKEY || HT[Hi] == key)//若单元Hi为空或者查找成功
            return Hi;
        cnt++;
        Hi = (H0 + i2) % m;//按照二次探测法计算下一个哈希地址
        if(Hi < 0)
            Hi += m;
        if(HT[Hi] == NULLKEY || HT[Hi] == key)//若单元Hi为空或者查找成功
            return Hi;
    }
    return -1;
}
void SearchHash(int HT[], int key)//在哈希表中查找关键字为key的元素
{
    int H0 = Hash(key);//计算哈希地址
    int Hi, cnt = 1;
    if(HT[H0] == NULLKEY)//如果单元H0为空，则所查元素不存在
        cout << "查找失败" << endl;
    else if(HT[H0] == key)
        cout << "查找成功" << "在第" << H0+1 << "个位置。比较次数：" << cnt << endl;
    else
    {
        //Hi = LineDetect(HT, H0, key, cnt);
        Hi = SecondDetect(HT, H0, key, cnt);
        if(HT[Hi] == key)//若单元Hi中元素的关键字为key，则查找成功
            cout << "查找成功" << "在第" << H0+1 << "个位置。比较次数：" << cnt << endl;
        else
            cout << "查找失败。比较次数：" << cnt << endl;
    }
}
bool InserHash(int HT[], int HC[],int key)
{
    int H0 = Hash(key);//计算哈希地址
    int Hi = -1, cnt = 1;
    if(HT[H0] == NULLKEY)//如果H0为空
    {
        HC[H0] = 1;//统计比较次数
        HT[H0] = key;//key入H0中
        return 1;
    }
    else
    {
        //Hi = LineDetect(HT, H0, key, cnt);//线性探测
        Hi = SecondDetect(HT, H0, key, cnt);//二次探测
        if(Hi != -1 && HT[Hi] == NULLKEY)
        {
            HC[Hi] = cnt;
            HT[Hi] = key;
            return 1;
        }
    }
    return 0;//error
}
void Print(int H[])
{
    for(int i = 0; i < m; i++)
        cout << H[i] << "\t";
    cout << endl;
}
int main()
{
    int key;
    int HT[m], HC[m];
    memset(HT, 0, sizeof(HT));
    memset(HC, 0, sizeof(HC));
    cout << "输入12个关键字，存入哈希表中：" << endl;
    for(int i = 0; i < 12; i++)
    {
        cin >> key;
        if(!InserHash(HT, HC, key))//创建哈希表
        {
            cout << "创建哈希表失败！" << endl;
            return 0;
        }
    }
    cout << "输出哈希表：" << endl;
    Print(HT);
    Print(HC);
    cout << "输入要查找的关键字：" << endl;
    cin >> key;
    SearchHash(HT, key);
    return 0;
}
//14 36 42 38 40 15 19 12 51 65 34 25
//14 36 42 38 40 15 19 12 51 65 34 18