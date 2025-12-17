#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int result = nums[0], temp = 1;

    for (int i = 0; i < nums.size(); i++) {
      result = max(result, nums[i]);
      if (nums[i] == 0) {
        temp = 1;
      } else {
        temp *= nums[i];
        result = max(result, temp);
      }
    }

    temp = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] == 0) {
        temp = 1;
      } else {
        temp *= nums[i];
        result = max(result, temp);
      }
    }

    return result;
  }
};

// 2 6 -12 -48
// -48 -24 -8 4

// -2 0 0
// 0 0 -1

int main() {
  vector<int> nums = {2, 3, -2, 4};
  int result = Solution().maxProduct(nums);
  cout << result << endl;
}
