#include <iostream>
#include <stack>
#include <deque> // 双端队列
using namespace std;

stack<int> state;
stack<char> symbol;
deque<char> str;

typedef struct
{
    int left;
    const char *right;
    int length;
} grammar;
grammar grammars[4] = {
    (grammar){'E', "S", 1},
    (grammar){'S', "BB", 2},
    (grammar){'B', "aB", 2},
    (grammar){'B', "b", 1}};
int action_tab[10][3] = { // 999为acc,-999为error
    {3, 4, -999},
    {-999, -999, 999},
    {6, 7, -999},
    {3, 4, -999},
    {-3, -3, -999},
    {-999, -999, -1},
    {6, 7, -999},
    {-999, -999, -3},
    {-2, -2, -999},
    {-999, -999, -2}};
int goto_tab[10][2] = {
    {1, 2},
    {-999, -999},
    {-999, 5},
    {-999, 8},
    {-999, -999},
    {-999, -999},
    {-999, 9},
    {-999, -999},
    {-999, -999},
    {-999, -999}};

void print_stack_deque(int step)
{
    printf("%d\t", step);
    stack<int> tempstate = state;
    stack<int> temp_state;
    while (!tempstate.empty())
    {
        temp_state.push(tempstate.top());
        tempstate.pop();
    }
    while (!temp_state.empty())
    {
        printf("%d", temp_state.top());
        temp_state.pop();
    }
    printf("\t");
    stack<char> tempsymbol = symbol;
    stack<char> temp_symbol;
    while (!tempsymbol.empty())
    {
        temp_symbol.push(tempsymbol.top());
        tempsymbol.pop();
    }
    while (!temp_symbol.empty())
    {
        printf("%c", temp_symbol.top());
        temp_symbol.pop();
    }
    printf("\t");
    deque<char> temp_str = str;
    while (!temp_str.empty())
    {
        printf("%c", temp_str.front());
        temp_str.pop_front();
    }
    printf("\t");
}

void Analysis()
{
    state.push(0);
    symbol.push('#'); // ab#SB 01234
    int step = 1;
    while (1)
    {
        print_stack_deque(step++);
        int index = 0;
        int flag = 0;
        if (str.front() == 'a')
            index = 0;
        else if (str.front() == 'b')
            index = 1;
        else if (str.front() == '#')
            index = 2;
        else if (str.front() == 'S')
        {
            index = 0;
            flag = 1;
        }
        else if (str.front() == 'B')
        {
            index = 1;
            flag = 1;
        }
        if (state.top() != 999 && flag == 0 && action_tab[state.top()][index] >= 0)
        {
            printf("S%d\t", action_tab[state.top()][index]);
            state.push(action_tab[state.top()][index]);
            char ch = ' ';
            if (index == 0)
                ch = 'a';
            else if (index == 1)
                ch = 'b';
            else if (index == 2)
                ch = '#';
            symbol.push(ch);
            str.pop_front();
        }
        else if (state.top() != 999 && flag == 1 && goto_tab[state.top()][index] >= 0)
        {
            printf("\t%d", goto_tab[state.top()][index]);
            state.push(goto_tab[state.top()][index]);
            char ch = ' ';
            if (index == 0)
                ch = 'S';
            else if (index == 1)
                ch = 'B';
            symbol.push(ch);
            str.pop_front();
        }
        else if (action_tab[state.top()][index] < 0 && action_tab[state.top()][index] != -999)
        {
            printf("r%d\t", -action_tab[state.top()][index]);
            int r = -1 * action_tab[state.top()][index];
            for (int i = 0; i < grammars[r].length; i++)
            {
                state.pop();
                symbol.pop();
            }
            str.push_front(grammars[r].left); // 归约
        }
        else if (state.top() == 999)
        {
            printf("acc");
            return;
        }
        else if (action_tab[state.top()][index] == -999)
        {
            printf("error!!!\n");
            return;
        }
        printf("\n");
    }
}

int main()
{
    char ch = ' ';
    printf("请输入表达式：\n");
    while (ch != '#')
    {
        ch = getchar();
        if ('a' != ch && 'b' != ch && '#' != ch)
        {
            printf("There are some wrong characters!");
            return 1;
        }
        else
            str.push_back(ch);
    }
    printf("步骤\t状态栈\t符号栈\t输入串\tACTION\tGOTO\n");
    Analysis();
    return 0;
}