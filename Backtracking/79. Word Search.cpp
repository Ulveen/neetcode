#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int rows, cols;

  bool backtrack(vector<vector<char>> &board, string word, int idx, int y,
                 int x) {

    if (idx == word.size()) {
      return true;
    }

    if (y < 0 || x < 0 || y >= rows || x >= cols || board[y][x] == '.' ||
        board[y][x] != word[idx]) {
      return false;
    }

    board[y][x] = '.';

    bool result = backtrack(board, word, idx + 1, y + 1, x) ||
                  backtrack(board, word, idx + 1, y, x + 1) ||
                  backtrack(board, word, idx + 1, y - 1, x) ||
                  backtrack(board, word, idx + 1, y, x - 1);

    board[y][x] = word[idx];

    return result;
  }

public:
  bool exist(vector<vector<char>> board, string word) {
    if (word.empty()) {
      return true;
    }

    rows = board.size();
    cols = board[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (word[0] == board[i][j]) {
          if (backtrack(board, word, 0, i, j)) {
            return true;
          }
        }
      }
    }

    return false;
  }
};

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'D'}, {'S', 'A', 'A', 'T'}, {'A', 'C', 'A', 'E'}};

  string word = "CAT";

  bool result = Solution().exist(board, word);
  if (result) {
    cout << "True";
  } else {
    cout << "False";
  }
  cout << endl;
}
