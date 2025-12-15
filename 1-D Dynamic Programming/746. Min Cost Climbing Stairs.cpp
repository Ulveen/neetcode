#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostCLimbingStairs(vector<int> &cost) {
    for (int i = 2; i < cost.size(); i++) {
      cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost.back(), cost[cost.size() - 2]);
  }
};

int main() {
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  int result = Solution().minCostCLimbingStairs(cost);
  printf("%d\n", result);
}
