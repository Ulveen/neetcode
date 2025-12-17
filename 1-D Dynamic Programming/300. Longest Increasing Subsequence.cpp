#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int result = 1;
    int n = nums.size();
    int dp[n];
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
      dp[i] = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      result = max(result, dp[i]);
    }

    return result;
  }
};

int main() {
  vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  int result = Solution().lengthOfLIS(nums);
  cout << result << endl;
}
