#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  void backtrack(vector<int> &nums, vector<int> combination, int idx) {
    unordered_set<int> check;

    for (int i = idx; i < nums.size(); i++) {
      if (check.find(nums[i]) != check.end()) {
        continue;
      }
      check.insert(nums[i]);
      combination.push_back(nums[i]);
      result.push_back(combination);
      backtrack(nums, combination, i + 1);
      combination.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    result = {{}};
    sort(nums.begin(), nums.end());
    backtrack(nums, {}, 0);
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> result = Solution().subsetsWithDup(nums);

  for (auto arr : result) {
    for (int num : arr) {
      cout << num << " ";
    }
    cout << endl;
  }
}
