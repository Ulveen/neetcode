#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool isValid;
  void dfs(vector<int> &result, vector<vector<int>> &mapping,
           vector<int> &state, int num) {

    if (!isValid) {
      return;
    }
    if (state[num] == 1) {
      isValid = false;
      return;
    }
    if (state[num] == 2) {
      return;
    }
    state[num] = 1;

    for (int pre : mapping[num]) {
      dfs(result, mapping, state, pre);
    }

    result.push_back(num);
    state[num] = 2;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    isValid = true;
    vector<vector<int>> mapping(numCourses);
    vector<int> result;

    for (auto v : prerequisites) {
      int a = v[0];
      int b = v[1];
      mapping[a].push_back(b);
    }

    vector<int> state(numCourses, 0);

    for (int i = 0; i < numCourses; i++) {
      dfs(result, mapping, state, i);
    }

    if (isValid) {
      return result;
    }
    return {};
  }
};

int main() {
  int numCourses = 4;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  vector<int> result = Solution().findOrder(numCourses, prerequisites);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
}
