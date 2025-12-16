#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);

    int dp[n - 1];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n - 1; i++) {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    int result1 = max(dp[n - 2], dp[n - 3]);
    dp[0] = nums[1];
    dp[1] = max(nums[1], nums[2]);

    for (int i = 2; i < n - 1; i++) {
      dp[i] = max(nums[i + 1] + dp[i - 2], dp[i - 1]);
    }
    int result2 = max(dp[n - 2], dp[n - 3]);
    cout << result1 << " " << result2 << endl;
    return max(result1, result2);
  }
};

int main() {
  vector<int> nums = {2, 9, 8, 3, 6};
  int result = Solution().rob(nums);

  cout << result << endl;
}
