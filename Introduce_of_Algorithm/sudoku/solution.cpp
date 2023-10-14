#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false; // 检查列
        if (board[row][i] == c)
            return false; // 检查行
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false; // 检查3x3宫格
    }                     // 检查对角线
    if (row == col)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][i] == c)
                return false;
        }
        if (row == 8 - col)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i][8 - i] == c)
                    return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solveSudoku(board))
                            return true;   // 如果找到一个有效解，结束递归
                        board[i][j] = '.'; // 否则回溯
                    }
                }
                return false; // 如果无法放置任何数字，则回溯
            }
        }
    }
    return true; // 整个板已填满，找到解
}

int main(int argc, char *argv[])
{
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    vector<vector<char>> board(9, vector<char>(9));

    // 读取输入
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    if (solveSudoku(board))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution" << endl;
    }

    return 0;
}
