#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool result;
  int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  void backtrack(vector<vector<char>> &board, string word, int idx, int lastY,
                 int lastX) {
    if (result) {
      return;
    }
    if (idx >= word.size()) {
      result = true;
      return;
    }
    if (idx == 0) {
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          if (board[i][j] == word[idx]) {
            board[i][j] = '.';
            backtrack(board, word, idx + 1, i, j);
            board[i][j] = word[idx];
          }
        }
      }
    } else {
      for (int i = 0; i < 4; i++) {
        int newY = lastY + dirs[i][0];
        int newX = lastX + dirs[i][1];

        if (newY < 0 || newX < 0 || newY >= board.size() ||
            newX >= board[0].size() || word[idx] != board[newY][newX]) {
          continue;
        }
        board[newY][newX] = '.';
        backtrack(board, word, idx + 1, newY, newX);
        board[newY][newX] = word[idx];
      }
    }
  }

public:
  bool exist(vector<vector<char>> board, string word) {
    result = false;
    backtrack(board, word, 0, -1, -1);
    return result;
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
