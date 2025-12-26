#include <iostream>
#include <numeric>
#include <unordered_set>
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
  int countComponents(int n, vector<vector<int>> &edges) {
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < edges.size(); i++) {
      int parentA = getParent(parent, edges[i][0]);
      int parentB = getParent(parent, edges[i][1]);

      parent[parentB] = parentA;
    }

    int result = 0;
    unordered_set<int> seen;

    for (int p : parent) {
      int temp = getParent(parent, p);
      if (seen.find(temp) == seen.end()) {
        seen.emplace(temp);
        result++;
      }
    }

    return result;
  }
};

int main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
  int result = Solution().countComponents(n, edges);
  cout << result << endl;
}
