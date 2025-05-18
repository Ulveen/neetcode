#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    int getGridNum(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }

    public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool grid[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int num = board[i][j] - '1';
                    int g = getGridNum(i, j);

                    if (row[i][num] || col[j][num] || grid[g][num]) {
                        return false;
                    }

                    row[i][num] = col[j][num] = grid[g][num] = true;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    bool result = Solution().isValidSudoku(board);
    printf("%s", result ? "true" : "false");
}