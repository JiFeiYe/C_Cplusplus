#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <numeric>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    if (row == col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][i] == c) return false;
        }
    }
    if (row == 8 - col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][8 - i] == c) return false;
        }
    }
    return true;
}

bool generateSudoku(vector<vector<char>>& board, int row, int col) {
    if (col == 9) {
        col = 0;
        row++;
    }
    if (row == 9) return true;

    vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    random_shuffle(nums.begin(), nums.end());

    for (char c : nums) {
        if (isValid(board, row, col, c)) {
            board[row][col] = c;
            if (generateSudoku(board, row, col + 1)) return true;
            board[row][col] = '.'; 
        }
    }
    return false;
}

void eraseNumbers(vector<vector<char>>& board) {
    vector<int> nums(81);
    iota(nums.begin(), nums.end(), 0);
    random_shuffle(nums.begin(), nums.end());

    int count = 0;
    for (int num : nums) {
        int i = num / 9;
        int j = num % 9;
        if (board[i][j] != '.') {
            board[i][j] = '.';
            count++;
            if (count == 81 - 30) break;
        }
    }
}

void writeToFile(vector<vector<char>>& board, string filename) {
    ofstream fout(filename);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fout << board[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

int main() {
    srand(time(NULL));

    for (int t = 0; t < 10; t++) {
        vector<vector<char>> board(9, vector<char>(9, '.'));
        if (generateSudoku(board, 0, 0)) {
            writeToFile(board, "test" + to_string(t + 1) + ".out");
            eraseNumbers(board);
            writeToFile(board, "test" + to_string(t + 1) + ".in");
        } else {
            cout << "No solution" << endl;
        }
    }

    return 0;
}
