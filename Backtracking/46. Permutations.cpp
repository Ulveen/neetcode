#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  void backtrack(vector<int> &nums, vector<bool> check,
                 vector<int> combination) {
    if (combination.size() == nums.size()) {
      result.push_back(combination);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (check[i]) {
        continue;
      }
      check[i] = true;
      combination.push_back(nums[i]);
      backtrack(nums, check, combination);
      combination.pop_back();
      check[i] = false;
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    result = {};
    vector<bool> check(nums.size(), false);
    backtrack(nums, check, {});
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = Solution().permute(nums);

  for (auto arr : result) {
    for (int num : arr) {
      cout << num << " ";
    }
    cout << endl;
  }
}
