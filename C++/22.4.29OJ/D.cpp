#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Television
{
private:
    int i = 1;//编号
    int k = 1;//模式：1是TV，2是DVD；
    int x = 1;//频道
    int sound = 50;
    static int count;//计数DVD
public:
    Television() = default;
    void Init(int n);
    void print();
    static int return_count();
    friend void remote(Television& t, int k_, int x_, int sound_);
};
int Television::count = 0;
void Television::Init(int n)
{
    i = n;
    x = n;
}
void Television::print()
{
    cout << "第" << i-1 << "号电视机--";
    if(k == 1)
    {
        cout << "TV模式--频道" << x << "--音量" << sound << endl;
    }
    else
    {
        cout << "DVD模式--频道99--音量" << sound << endl;
    }
}
int Television::return_count()
{
    return count;
}
void remote(Television& t, int k_, int x_, int sound_)
{
    if(k_ == 2 && t.k == 1)
    {
        t.k = k_;
        t.x = 99;
        t.count++;
    }
    else if(t.k == 2 && k_ == 1)
    {
        t.count--;
        t.k = k_;
        t.x = x_;
    }
    else if(t.k == 1 && k_ == 1)
    {
        t.x = x_;
    }
    t.sound += sound_;
    if(t.sound <= 0)
    {
        t.sound = 0;
    }
    else if(t.sound >= 100)
    {
        t.sound = 100;
    }
    t.print();
}

int main()
{
    int n = 0;
    cin >> n;
    Television* tv = new Television[n];
    for(int j = 0; j < n; j++)
    {
        tv[j].Init(j+1);//第0台电视机编号为1,频道为1
    }
    int i = 0, k = 0, x = 0;
    int changesound = 0;
    int t = 0;
    cin >> t;
    while(t--)
    {
        cin >> i >> k >> x >> changesound;
        remote(tv[i], k, x, changesound);
    }
    cout << "播放电视的电视机数量为" << n - Television::return_count() << endl;
    cout << "播放DVD的电视机数量为" << Television::return_count() << endl;
    return 0;
}