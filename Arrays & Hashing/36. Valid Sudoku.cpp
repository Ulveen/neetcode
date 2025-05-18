#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
    int getGridNum(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }

    public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;
        unordered_map<int, unordered_set<int>> grid;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int a = board[i][j] - '0';
                    int g = getGridNum(i, j);
                    if (row[i].find(a) != row[i].end() || 
                        col[j].find(a) != col[j].end() ||
                        grid[g].find(a) != grid[g].end()
                    ) {
                        return false;
                    }
                    row[i].insert(a);
                    col[j].insert(a);
                    grid[g].insert(a);
                }
            }
        }

        return true;
    }
};

int main() {
    // vector<vector<char>> board = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}
    // };

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