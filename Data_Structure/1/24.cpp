#include<iostream>

#include<time.h>
//#include<cmath>
#include<windows.h>
using namespace std;

double card[14];            //卡牌剩余数
double test[4];             //卡牌抽取数
double test_arrange[24][4]; //test全排序（24）i
const char Operator[4] = {'+','-','*','/'};
char Ope[64][3];            //抽取运算符（64）j
double answer;

void GetTest()//抽牌
{   
    srand((unsigned int)(time(NULL)));
    for(int i = 0; i < 4; i++)
    {
        int ran = rand() % 13 + 1;//ran = 1 2 3 ... 12 13;
        if(card[ran] != 0)
        {
            test[i] = ran;
            card[ran]--;
        }
        else
            i--;
    }
    return;
}

void Arrange()//全排列
{
    int u, v, w, x;
    int i = 0;
    for(u = 0; u < 4; u++)
    for(v = 0; v < 4; v++)
    for(w = 0; w < 4; w++)
    for(x = 0; x < 4; x++)
        if(!(x==w||x==v||x==u||w==v||w==u||v==u))
        {
            test_arrange[i][0] = test[u]; 
            test_arrange[i][1] = test[v];
            test_arrange[i][2] = test[w];
            test_arrange[i][3] = test[x];
            i++;
        }
    i = 0;
    for(u = 0; u < 4; u++)
    for(v = 0; v < 4; v++)
    for(w = 0; w < 4; w++)
    {   
        Ope[i][0] = Operator[u];
        Ope[i][1] = Operator[v];
        Ope[i][2] = Operator[w];
        i++;
    }
    return;
}
void Calculate()//计算（一次抽牌）
{
    answer = 0;
    int i, j;
    for(i = 0; i < 24; i++)
    for(j = 0; j < 64; j++)
    {
        if(Ope[j][0] == '+')
        {
            answer += test_arrange[i][0] + test_arrange[i][1];
        }
        else if(Ope[j][0] == '-')
        {
            answer += test_arrange[i][0] - test_arrange[i][1];
        }
        else if(Ope[j][0] == '*')
        {
            answer += test_arrange[i][0] * test_arrange[i][1];
        }
        else if(Ope[j][0] == '/')
        {
            answer += test_arrange[i][0] / test_arrange[i][1];
        }
        int u;
        for(u = 1; u < 3; u++)
        {
            if(Ope[j][u] == '+')
            {
                answer += test_arrange[i][u+1];
            }
            else if(Ope[j][u] == '-')
            {
                answer -= test_arrange[i][u+1];
            }
            else if(Ope[j][u] == '*')
            {
                answer *= test_arrange[i][u+1];
            }
            else if(Ope[j][u] == '/')
            {
                answer /= test_arrange[i][u+1];
            }
        }
        if(answer == 24)
        {
            if(((Ope[j][0] == '+' || Ope[j][0] == '-') && (Ope[j][1] == '+' || Ope[j][1] == '-') && (Ope[j][2] == '+' || Ope[j][2] == '-'))
                || ((Ope[j][0] == '*' || Ope[j][0] == '/') && (Ope[j][1] == '+' || Ope[j][1] == '-') && (Ope[j][2] == '+' || Ope[j][2] == '-'))
                || ((Ope[j][0] == '*' || Ope[j][0] == '/') && (Ope[j][1] == '*' || Ope[j][1] == '/') && (Ope[j][2] == '+' || Ope[j][2] == '-'))
                || ((Ope[j][0] == '*' || Ope[j][0] == '/') && (Ope[j][1] == '*' || Ope[j][1] == '/') && (Ope[j][2] == '*' || Ope[j][2] == '/')))
            {
                cout << test_arrange[i][0] << Ope[j][0] 
                << test_arrange[i][1] << Ope[j][1] 
                << test_arrange[i][2] << Ope[j][2]
                << test_arrange[i][3] << " = 24" << endl; 
            }
            else if(((Ope[j][0] == '+' || Ope[j][0] == '-') && (Ope[j][1] == '*' || Ope[j][1] == '/') && (Ope[j][2] == '*' || Ope[j][2] == '/'))
                || ((Ope[j][0] == '+' || Ope[j][0] == '-') && (Ope[j][1] == '*' || Ope[j][1] == '/') && (Ope[j][2] == '+' || Ope[j][2] == '-')))
            {
                cout << "(" << test_arrange[i][0] << Ope[j][0]
                << test_arrange[i][1] << ")" << Ope[j][1] 
                << test_arrange[i][2] << Ope[j][2]
                << test_arrange[i][3] << " = 24" << endl;
            }
            else if(((Ope[j][0] == '+' || Ope[j][0] == '-') && (Ope[j][1] == '+' || Ope[j][1] == '-') && (Ope[j][2] == '*' || Ope[j][2] == '/'))
                    || ((Ope[j][0] == '*' || Ope[j][0] == '/') && (Ope[j][1] == '+' || Ope[j][1] == '-') && (Ope[j][2] == '*' || Ope[j][2] == '/')))
            {
                cout << "(" << test_arrange[i][0] << Ope[j][0]
                << test_arrange[i][1] << Ope[j][1] 
                << test_arrange[i][2] << ")" << Ope[j][2]
                << test_arrange[i][3] << " = 24" << endl;
            }
            else
            {
                cout << "aaaaaaaaaaaa";
                cout << test_arrange[i][0] << Ope[j][0] 
                << test_arrange[i][1] << Ope[j][1] 
                << test_arrange[i][2] << Ope[j][2]
                << test_arrange[i][3] << " = 24"; 
                cout << "aaaaaaaaaaaa" << endl;
            }
            return;
        }
        else
            answer = 0;
    }
    cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] << " " << "flase" << endl;
    return;
}


int main()
{
    card[0] = -1;
    for(int i = 1; i < 14; i++)
        card[i] = 4;
    for(int i = 0 ; i < 13; i++)
    {
        GetTest();
        Arrange();
        Calculate();
        Sleep(1000);
    }
    return 0;
}