#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool flag;
  void iter(vector<int> &nums, int suffix[], int idx, int currSum) {
    if (flag) {
      return;
    }

    if (idx >= nums.size()) {
      if (currSum == 0) {
        flag = true;
      }
      return;
    }

    if (abs(currSum) > abs(suffix[idx])) {
      return;
    }

    iter(nums, suffix, idx + 1, currSum + nums[idx]);
    iter(nums, suffix, idx + 1, currSum - nums[idx]);
  }

public:
  bool canPartition(vector<int> &nums) {
    flag = false;
    int n = nums.size();
    int suffix[n];
    suffix[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = suffix[i + 1] + nums[i];
    }

    iter(nums, suffix, 0, 0);

    return flag;
  }
};

int main() {
  vector<int> nums = {1, 5, 11, 5};
  bool result = Solution().canPartition(nums);

  if (result) {
    cout << "True";
  } else {
    cout << "False";
  }
  puts("");
}
