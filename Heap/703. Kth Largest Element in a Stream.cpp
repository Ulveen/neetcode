#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

public:
  KthLargest(int k, vector<int> &nums) {
    pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(),
                                                        nums.end());

    this->k = k;

    while (pq.size() > k) {
      pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    while (pq.size() > this->k) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  int k = 3;
  vector<int> nums = {4, 5, 8, 2};
  vector<int> addNums = {3, 5, 10, 9, 4};

  KthLargest obj = KthLargest(k, nums);

  for (int num : addNums) {
    int result = obj.add(num);
    cout << result << " ";
  }
  cout << endl;
}
