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
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (auto e : edges) {
      int parentA = getParent(parent, e[0]);
      int parentB = getParent(parent, e[1]);

      if (parentA == parentB) {
        return e;
      }
      parent[parentB] = parentA;
    }

    return {};
  }
};

int main() {
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  vector<int> result = Solution().findRedundantConnection(edges);

  cout << result[0] << " " << result[1] << endl;
}
