#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
  int getParent(vector<int> &parent, int num) {
    if (parent[num] == num) {
      return num;
    }
    parent[num] = getParent(parent, parent[num]);
    return parent[num];
  }

public:
  bool validTree(int n, vector<vector<int>> &edges) {
    if (edges.size() != n - 1) {
      return false;
    }

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    for (auto edge : edges) {
      int parentA = getParent(parent, edge[0]);
      int parentB = getParent(parent, edge[1]);

      if (parentA == parentB) {
        return false;
      }
      parent[parentB] = parentA;
    }

    return true;
  }
};

int main() {
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

  bool result = Solution().validTree(n, edges);
  if (result) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
}
