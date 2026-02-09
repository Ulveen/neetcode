#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());

    for (int i = 0; i < k - 1; i++) {
      pq.pop();
    }

    return pq.top();
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;

  int result = Solution().findKthLargest(nums, k);
  cout << result << endl;
}
