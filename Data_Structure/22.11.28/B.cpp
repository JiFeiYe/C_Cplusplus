#include<iostream>
#include<cstring>
using namespace std;
#define NULLKEY 0//单元为空的标记

int m, n;
int HT[10005], HC[10005];

int Hash(int key)//哈希函数
{
    return key%11;
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
    for(int i = 1; i <= m; i++)
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
    int cnt = 1;
    if(HT[H0] == NULLKEY)//如果单元H0为空，则所查元素不存在
        cout << "0 " << cnt << endl;
    else if(HT[H0] == key)
        cout << "1 "<< cnt << " " << H0+1 << endl;
    else
    {
        //H0 = LineDetect(HT, H0, key, cnt);
        H0 = SecondDetect(HT, H0, key, cnt);
        if(HT[H0] == key)//若单元Hi中元素的关键字为key，则查找成功
            cout << "1 " << cnt << " " << H0+1 << endl;
        else
            cout << "0 " << cnt << endl;
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
        return 0;
    }
    else
    {
        //Hi = LineDetect(HT, H0, key, cnt);//线性探测
        Hi = SecondDetect(HT, H0, key, cnt);//二次探测
        if(Hi != -1 && HT[Hi] == NULLKEY)
        {
            HC[Hi] = cnt;
            HT[Hi] = key;
            return 0;
        }
    }
    return 1;//error
}
void Print(int H[])
{
    cout << H[0];
    for(int i = 1; i < m; i++)
    {
        if(H[i] == 0)
            cout << " " << "NULL";
        else
            cout << " " << H[i];
    }
    cout << endl;
}
int main()
{
    freopen("C:\\Users\\LLeavee\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\LLeavee\\Desktop\\answer.txt", "w", stdout);
    int key;
    int t = 0;
    cin >> t;
    while(t--)
    {
        memset(HT, 0x3f3f3f, sizeof(HT));
        memset(HC, 0, sizeof(HC));
        cin >> m >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> key;
            if(InserHash(HT, HC, key))//创建哈希表
            {
                cout << "创建哈希表失败！" << endl;
                break;
                // return 0;
            }
        }
        Print(HT);
        int k = 0;
        cin >> k;
        while(k--)
        {
            cin >> key;
            SearchHash(HT, key);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
