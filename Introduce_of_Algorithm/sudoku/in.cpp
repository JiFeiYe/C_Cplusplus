#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

// 生成数据组数
#define NUM 10
// 正解程序名
#define SLN "out.exe"

struct Board
{
    int num = 0;
    char space = '.';
} board[9][9];

bool is_Valid(int row, int col, int val) // 判断行列宫重复
{
    for (int i = 0; i < 9; i++) // 行重复
    {
        if (board[row][i].num == val)
            return false;
    }
    for (int j = 0; j < 9; j++) // 列重复
    {
        if (board[j][col].num == val)
            return false;
    }
    int r = row / 3 * 3;
    int c = col / 3 * 3;
    for (int i = r; i < r + 3; i++) // 宫重复
    {
        for (int j = c; j < c + 3; j++)
        {
            if (board[i][j].num == val)
                return false;
        }
    }
    return true;
}

void swap_row(int row1, int row2) // 行交换
{
    int temp[9];
    for (int i = 0; i < 9; i++)
    {
        temp[i] = board[row1][i].num;
    }
    for (int i = 0; i < 9; i++)
    {
        board[row1][i].num = board[row2][i].num;
    }
    for (int i = 0; i < 9; i++)
    {
        board[row2][i].num = temp[i];
    }
}
void swap_col(int col1, int col2) // 列交换
{
    int temp[9];
    for (int i = 0; i < 9; i++)
    {
        temp[i] = board[i][col1].num;
    }
    for (int i = 0; i < 9; i++)
    {
        board[i][col1].num = board[i][col2].num;
    }
    for (int i = 0; i < 9; i++)
    {
        board[i][col2].num = temp[i];
    }
}
void swap(int &x, int &y) // 俩数交换
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

void wipe(int times) // 擦除数字
{
    const int max_wipe = 64;
    const int min_wipe = 14;
    srand((unsigned int)(time(NULL)));
    if (times > max_wipe)
        times = max_wipe;
    else if (times < min_wipe)
        times = min_wipe;

    int wipes[81];
    for (int i = 0; i <= 80; i++)
    {
        wipes[i] = i;
    }
    for (int i = 80; i >= 1; i--)
    {
        swap(wipes[i], wipes[rand() % i]); // 获得81个0~80的不重复随机数
    }

    for (int i = 0; i < times; i++) // 擦除
    {
        int row = wipes[i] / 9;
        int col = wipes[i] % 9;
        board[row][col].num = 0;
    }
}

int main()
{
    srand((unsigned int)(time(NULL)));
    for (int T = 0; T < NUM; ++T)
    {
        // 生成输入or输出文件名
        std::string iname = "t", oname = "t";
        iname += std::to_string(T) + ".in";
        oname += std::to_string(T) + ".out";

        // 链接写入输入文件
        freopen(iname.c_str(), "w", stdout);
        //////////////////////////////////////////////////
        // 这里填入你的数据生成程序，直接用标准输出即可
        // 初始化
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j].num = 0;
            }
        }
        int num = (rand() % 9) + 1;                         // 获得1~9随机数
        for (int row_index = 0; row_index < 9; row_index++) // 生成数独基本盘
        {
            for (int col_index = 0; col_index < 9; col_index++)
            {
                while (!is_Valid(row_index, col_index, num))
                    num = num % 9 + 1; // 下一个数
                board[row_index][col_index].num = num;
                num = num % 9 + 1;
            }
        }

        for (int times = 0; times < 100; times++) // 互换一百次获得终盘
        {
            int row_range_base = rand() % 3 * 3; // 随机获得0、3、6其中一个
            int temp_range = rand() % 3;
            int row1;
            int row2;
            if (temp_range == 0)
            {
                row1 = 1;
                row2 = 2;
            }
            else if (temp_range == 1)
            {
                row1 = 0;
                row2 = 2;
            }
            else if (temp_range == 2)
            {
                row1 = 0;
                row2 = 1;
            }
            swap_row(row_range_base + row1, row_range_base + row2); // 交换两行

            int col_range_base = rand() % 3 * 3; // 随机获得0、3、6其中一个
            temp_range = rand() % 3;
            int col1;
            int col2;
            if (temp_range == 0)
            {
                col1 = 1;
                col2 = 2;
            }
            else if (temp_range == 1)
            {
                col1 = 0;
                col2 = 2;
            }
            else if (temp_range == 2)
            {
                col1 = 0;
                col2 = 1;
            }
            swap_col(col_range_base + col1, col_range_base + col2); // 交换两列
        }

        int times = rand() % 81;
        wipe(times); // 随机擦除times次数字 14 <= times <= 64

        for (int i = 0; i < 9; i++) // 输出
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j].num != 0)
                    std::cout << board[i][j].num << ' ';
                else
                    std::cout << board[i][j].space << ' ';
            }
            if (board[i][8].num != 0)
                std::cout << board[i][8].num << std::endl;
            else
                std::cout << board[i][8].space << std::endl;
        }
        //////////////////////////////////////////////////
        // 关闭文件
        fclose(stdout);

        // 生成调用命令
        std::string call(SLN);
        call += ' ';
        call += iname + ' ' + oname;

        // 调用正解程序
        system(call.c_str());
    }
    return 0;
}