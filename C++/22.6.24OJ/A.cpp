#include<iostream>
using namespace std;

class Member
{
protected:
    int id;
    string name;
    int score;
public:
    Member() = default;
    Member(int id_, string name_, int score_);
    virtual void add(int cost);
    virtual int exchange(int score_);
    virtual void print();
};
Member::Member(int id_, string name_, int score_)
{
    id = id_; name = name_; score = score_;
}
void Member::add(int cost)
{
    score += cost;
}
int Member::exchange(int score_)
{
    score -= score_ / 100 * 100;
    return score / 100;
}
void Member::print()
{
    cout << "普通会员" << id << "--" << name << "--" << score << endl;
    return;
}

class VIP:public Member
{
private:
    int addpresent;
    int expresent;
public:
    VIP(int id_, string name_, int score_, int addpresent_, int expresent_):
    Member(id_, name_, score_)
    {
        addpresent = addpresent_; expresent = expresent_;
    } 
    void add(int cost);
    int exchange(int score_);
    void print();
};
void VIP::add(int cost)
{
    score += cost*addpresent;
}
int VIP::exchange(int score_)
{
    score -= score_ / expresent * expresent;
    return score_ / expresent;
}
void VIP::print()
{
    cout << "贵宾会员" << id << "--" << name << "--" << score << endl;
    return;
}

int main()
{
	// 创建一个基类对象指针
	Member* pm = NULL;
	// ....其他变量自行编写
    int id = 0, score = 0;
    string name;
	// 输入数据，创建普通会员对象mm
    cin >> id >> name >> score;
    Member mm(id, name, score);
	// 使用指针pm执行以下操作：
    int cost = 0, score_ = 0;
	// 1、pm指向普通会员对象mm
    pm = &mm;
	// 2、输入数据，通过pm执行积分累加和积分兑换
    cin >> cost >> score_;
    pm->add(cost);
    pm->exchange(score_);
	// 3、通过pm调用打印方法输出
    pm->print();
	// 输入数据，创建贵宾会员对象vv
    int addpresent = 0, expresent = 0;
    cin >> id >> name >> score >> addpresent >> expresent;
    VIP vv(id, name, score, addpresent, expresent);
	// 使用指针pm执行以下操作：
	// 1、pm指向贵宾会员对象vv
    pm = &vv;
	// 2、输入数据，通过pm执行积分累加和积分兑换
    cin >> cost >> score_;
    pm->add(cost);
    pm->exchange(score_);
	// 3、通过pm调用打印方法输出
    pm->print();
	return 0;
}