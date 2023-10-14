#include <iostream>
using namespace std;

class Metal
{
private:
    int hardness;
    int weight;
    int volume;
public:
    Metal() = default;
    Metal(int hardness_, int weight_, int volume_);
    friend Metal operator +(Metal& a, Metal& b);
    friend Metal operator *(Metal& a, int& n);
    Metal& operator ++();//前增量
    Metal operator --(int);//后增量
    void print();
};
Metal::Metal(int hardness_, int weight_, int volume_)
{
    hardness = hardness_; weight = weight_; volume = volume_;
}
Metal operator +(Metal& a, Metal& b)
{
    Metal temp(a.hardness, a.weight, a.volume);
    temp.hardness += b.hardness; temp.weight += b.weight; temp.volume += b.volume;
    return temp;
}
Metal operator *(Metal& a, int& n)
{
    Metal temp(a.hardness, a.weight, a.volume);
    temp.volume = a.volume * n;
    return temp;
}
Metal& Metal::operator++()
{
    hardness += 1;
    weight *= 1.1;
    volume *= 1.1;
    return *this;
}
Metal Metal::operator--(int)
{
    hardness -= 1;
    weight *= 0.9;
    volume *= 0.9;
    return *this;
}
void Metal::print()
{
    cout << "硬度" << hardness << "--重量" << weight << "--体积" << volume << endl;
    return;
}

int main()
{
    int hardness = 0, weight = 0, volume = 0;
    cin >> hardness >> weight >> volume;
    Metal m1(hardness, weight, volume);
    cin >> hardness >> weight >> volume;
    Metal m2(hardness, weight, volume);
    int n = 0;
    cin >> n;
    Metal m3;
    m3 = m1 + m2;
    m3.print();
    Metal m4;
    m4 = m1 * n;
    m4.print();
    ++m1;
    m1.print();
    m2--;
    m2.print();
    return 0;
}