#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    int y, x;

    while (pq.size() > 1) {
      y = pq.top();
      pq.pop();
      x = pq.top();
      pq.pop();

      if (y != x) {
        pq.push(y - x);
      }
    }

    if (pq.size() > 0) {
      return pq.top();
    }
    return 0;
  }
};

int main() {
  vector<int> stones = {2, 2};
  int result = Solution().lastStoneWeight(stones);
  cout << result << endl;
}
