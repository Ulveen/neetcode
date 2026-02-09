#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int maxVal = amount + 1;
    int dp[maxVal];
    dp[amount] = maxVal;
    dp[0] = 0;

    sort(coins.begin(), coins.end());

    for (int i = 1; i <= amount; i++) {
      dp[i] = maxVal;
      for (int coin : coins) {
        if (coin > i)
          break;
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  int result = Solution().coinChange(coins, amount);

  printf("result %d\n", result);
}
