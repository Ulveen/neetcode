#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;

    int dp[amount + 1];
    dp[0] = -1;

    for (int i = 1; i <= amount; i++) {
      dp[i] = -1;
      for (int coin : coins) {
        if (coin > i)
          continue;

        if (coin == i) {
          dp[i] = 1;
          break;
        }

        int candidate = -1;
        if (i % coin == 0) {
          candidate = i / coin;
        }

        if (dp[i - coin] != -1) {
          int a = dp[i - coin] + 1;
          if (candidate == -1) {
            candidate = a;
          } else {
            candidate = min(candidate, a);
          }
        }

        if (candidate == -1)
          continue;

        if (dp[i] == -1) {
          dp[i] = candidate;
        } else {
          dp[i] = min(dp[i], candidate);
        }
        continue;
      }
    }

    // for (int i = 0; i <= amount; i++) {
    //   cout << dp[i] << " ";
    // }
    // puts("");

    return dp[amount];
  }
};

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  int result = Solution().coinChange(coins, amount);

  printf("result %d\n", result);
}
