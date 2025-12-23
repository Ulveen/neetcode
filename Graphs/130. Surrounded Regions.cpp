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
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 1; i < rows - 1; i++) {
      for (int j = 1; j < cols - 1; j++) {
        if (board[i][j] == 'X' || visited[i][j]) {
          continue;
        } else {
          bool isValid = true;
          queue<pair<int, int>> q;
          vector<pair<int, int>> v;

          q.push({i, j});
          v.push_back({i, j});

          while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
              int ny = y + moveY[i];
              int nx = x + moveX[i];

              if (ny < 0 || nx < 0 || ny >= rows || nx >= cols ||
                  board[ny][nx] == 'X' || visited[ny][nx]) {
                continue;
              }

              if (ny == 0 || nx == 0 || ny == rows - 1 || nx == cols - 1) {
                isValid = false;
              }

              visited[ny][nx] = true;
              q.push({ny, nx});
              v.push_back({ny, nx});
            }
          }

          if (isValid) {
            for (auto [y, x] : v) {
              board[y][x] = 'X';
            }
          }
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
