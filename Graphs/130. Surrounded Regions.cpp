#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  int moveY[4] = {-1, 1, 0, 0};
  int moveX[4] = {0, 0, -1, 1};

public:
  void solve(vector<vector<char>> &board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> isValid(rows, vector<bool>(cols, true));
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; i++) {
      if (board[i][0] == 'O') {
        q.push({i, 0});
        isValid[i][0] = false;
      }
      if (board[i][cols - 1] == 'O') {
        q.push({i, cols - 1});
        isValid[i][cols - 1] = false;
      }
    }

    for (int i = 0; i < cols; i++) {
      if (board[0][i] == 'O') {
        q.push({0, i});
        isValid[0][i] = false;
      }
      if (board[rows - 1][i] == 'O') {
        q.push({rows - 1, i});
        isValid[rows - 1][i] = false;
      }
    }

    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];

        if (ny < 0 || nx < 0 || ny >= rows || nx >= cols ||
            board[ny][nx] == 'X' || !isValid[ny][nx]) {
          continue;
        }
        q.push({ny, nx});
        isValid[ny][nx] = false;
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (isValid[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main() {
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'X', 'O'}};
  Solution().solve(board);
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
