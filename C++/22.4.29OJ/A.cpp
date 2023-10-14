#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Robots
{
private:
    char* name = NULL;
    char type;
    int level;
public:
    Robots(char* name_, char type_, int level_);
    bool change(char type_);
    void show();
    ~Robots();
};
Robots::Robots(char* name_, char type_, int level_)
{
    type = type_;
    level = level_;
    name = new char[21];
    strcpy(name, name_);
}
bool Robots::change(char type_)
{
    if(type_ == type)
    {
        return false;
    }
    else
    {
        type = type_;
        return true;
    }
}
void Robots::show()
{
    cout << name << "--" << type << "--" << level << "--";
    if(type == 'N')
    {
        cout << level*5 << "--" << level*5 << "--" << level*5 << endl;
    }
    else if(type == 'A')
    {
        cout << level*5 << "--" << level*10 << "--" << level*5 << endl;
    }
    else if(type == 'D')
    {
        cout << level*5 << "--" << level*5 << "--" << level*10 << endl;
    }
    else
    {
        cout << level*50 << "--" << level*5 << "--" << level*5 << endl;
    }
    return;
}
Robots::~Robots()
{
    delete[] name;
}

int main()
{
    int t = 0;
    cin >> t;
    char name[21] = {" "};
    char type = 'A';
    int level = 0;
    int count = 0;
    while(t--)
    {
        cin >> name >> type >> level;
        Robots rob(name, type, level);
        cin >> type;
        if(rob.change(type))
        {
            count++;
        }
        rob.show();
    }
    cout << "The number of robot transform is " << count;
    return 0;
}