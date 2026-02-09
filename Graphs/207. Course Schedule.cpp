#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool hasCycle(vector<vector<int>> &pre, vector<int> &state, int num) {
    if (state[num] == 2) {
      return false;
    }
    if (state[num] == 1) {
      return true;
    }

    state[num] = 1;
    for (int x : pre[num]) {
      if (hasCycle(pre, state, x)) {
        return true;
      }
    }
    state[num] = 2;

    return false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> pre(numCourses);

    for (auto v : prerequisites) {
      int a = v[0], b = v[1];
      pre[a].push_back(b);
    }

    vector<int> state(numCourses);

    for (int i = 0; i < numCourses; i++) {
      if (hasCycle(pre, state, i)) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  vector<vector<int>> prerequisites = {{1, 0}, {1, 2}, {0, 1}};
  int numCourses = 3;

  bool result = Solution().canFinish(numCourses, prerequisites);
  if (result) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
}
