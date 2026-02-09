#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y;
  int x;
  int distance;

  Node(int _y, int _x, int _distance) : y(_y), x(_x), distance(_distance) {}
};

class Solution {
private:
  int moveY[4] = {-1, 1, 0, 0};
  int moveX[4] = {0, 0, -1, 1};
  const int EMPTY = INT_MAX;

public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    queue<Node> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 0) {
          q.push(Node(i, j, 0));
        }
      }
    }

    while (!q.empty()) {
      Node node = q.front();
      q.pop();

      if (grid[node.y][node.x] == -1) {
        continue;
      }

      grid[node.y][node.x] = min(grid[node.y][node.x], node.distance);

      for (int k = 0; k < 4; k++) {
        int newY = node.y + moveY[k];
        int newX = node.x + moveX[k];

        if (newY < 0 || newX < 0 || newY >= grid.size() ||
            newX >= grid[0].size() || grid[newY][newX] != EMPTY) {
          continue;
        }
        q.push(Node(newY, newX, node.distance + 1));
      }
    }
  }
};

int main() {
  vector<vector<int>> grid = {{2147483647, -1, 0, 2147483647},
                              {2147483647, 2147483647, 2147483647, -1},
                              {2147483647, -1, 2147483647, -1},
                              {0, -1, 2147483647, 2147483647}};
  Solution().islandsAndTreasure(grid);

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
