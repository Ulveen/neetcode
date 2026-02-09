#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  int moveY[4] = {-1, 1, 0, 0};
  int moveX[4] = {0, 0, -1, 1};

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {

    vector<vector<int>> result = {};
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

    queue<pair<int, int>> qp, qa;

    for (int i = 0; i < rows; i++) {
      pacific[i][0] = true;
      atlantic[i][cols - 1] = true;
      qp.push({i, 0});
      qa.push({i, cols - 1});
    }

    for (int j = 0; j < cols; j++) {
      pacific[0][j] = true;
      atlantic[rows - 1][j] = true;
      qp.push({0, j});
      qa.push({rows - 1, j});
    }

    while (!qp.empty()) {
      pair<int, int> c = qp.front();
      qp.pop();

      for (int i = 0; i < 4; i++) {
        int ny = c.first + moveY[i];
        int nx = c.second + moveX[i];

        if (ny < 0 || nx < 0 || ny >= rows || nx >= cols || pacific[ny][nx] ||
            heights[ny][nx] < heights[c.first][c.second]) {
          continue;
        }
        pacific[ny][nx] = true;
        qp.push({ny, nx});
      }
    }

    while (!qa.empty()) {
      pair<int, int> c = qa.front();
      qa.pop();

      for (int i = 0; i < 4; i++) {
        int ny = c.first + moveY[i];
        int nx = c.second + moveX[i];

        if (ny < 0 || nx < 0 || ny >= rows || nx >= cols || atlantic[ny][nx] ||
            heights[ny][nx] < heights[c.first][c.second]) {
          continue;
        }
        atlantic[ny][nx] = true;
        qa.push({ny, nx});
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }

    // cout << "Pacific" << endl;
    // for (int i = 0; i < rows; i++) {
    //   for (int j = 0; j < cols; j++) {
    //     cout << pacific[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    //
    // cout << "Atlantic" << endl;
    //
    // for (int i = 0; i < rows; i++) {
    //   for (int j = 0; j < cols; j++) {
    //     cout << atlantic[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    return result;
  }
};

int main() {
  vector<vector<int>> heights = {
      {4, 2, 7, 3, 4}, {7, 4, 6, 4, 7}, {6, 3, 5, 3, 6}};
  vector<vector<int>> result = Solution().pacificAtlantic(heights);

  for (vector<int> v : result) {
    for (int num : v) {
      cout << num << " ";
    }
    cout << endl;
  }
}
