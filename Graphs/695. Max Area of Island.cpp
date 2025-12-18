#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int floodfill(vector<vector<int>> &grid, int y, int x) {
    if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size() ||
        grid[y][x] == 0) {
      return 0;
    }
    grid[y][x] = 0;
    return 1 + floodfill(grid, y + 1, x) + floodfill(grid, y - 1, x) +
           floodfill(grid, y, x + 1) + floodfill(grid, y, x - 1);
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int result = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          result = max(result, floodfill(grid, i, j));
        }
      }
    }

    return result;
  }
};

int main() {
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  int result = Solution().maxAreaOfIsland(grid);
  cout << result << endl;
}
