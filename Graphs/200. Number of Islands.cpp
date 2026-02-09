#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void floodfill(vector<vector<char>> &grid, int y, int x) {
    if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size() ||
        grid[y][x] == '0') {
      return;
    }
    grid[y][x] = '0';
    floodfill(grid, y - 1, x);
    floodfill(grid, y + 1, x);
    floodfill(grid, y, x - 1);
    floodfill(grid, y, x + 1);
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int result = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          result++;
          floodfill(grid, i, j);
        }
      }
    }

    return result;
  }
};

int main() {
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};

  int result = Solution().numIslands(grid);
  cout << result << endl;
}
