#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  int moveY[4] = {-1, 1, 0, 0};
  int moveX[4] = {0, 0, -1, 1};

public:
  int orangesRotting(vector<vector<int>> &grid) {
    int result = 0;
    int freshCount = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          freshCount++;
        }
      }
    }

    while (freshCount > 0) {
      int changeCount = 0;
      int iterCount = q.size();

      for (int i = 0; i < iterCount; i++) {
        pair<int, int> c = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int newY = c.first + moveY[i];
          int newX = c.second + moveX[i];

          if (newY < 0 || newX < 0 || newY >= grid.size() ||
              newX >= grid[0].size() || grid[newY][newX] != 1) {
            continue;
          }
          grid[newY][newX] = 2;
          changeCount++;
          q.push({newY, newX});
        }
      }

      result++;

      if (changeCount == 0) {
        return -1;
      }

      freshCount -= changeCount;
    }

    return result;
  }
};

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
  int result = Solution().orangesRotting(grid);

  cout << result << endl;
}
