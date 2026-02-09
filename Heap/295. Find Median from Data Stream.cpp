#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (minHeap.empty() && maxHeap.empty()) {
      minHeap.push(num);
      return;
    }
    if (maxHeap.empty()) {
      if (minHeap.top() < num) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(num);
      } else {
        maxHeap.push(num);
      }
      return;
    }

    if (num > minHeap.top()) {
      minHeap.push(num);
    } else {
      maxHeap.push(num);
    }

    int diff = maxHeap.size() - minHeap.size();
    if (abs(diff) > 1) {
      if (diff < 0) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      } else {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
    }
  }

  double findMedian() {
    if (minHeap.size() > maxHeap.size()) {
      return minHeap.top();
    }
    if (maxHeap.size() > minHeap.size()) {
      return maxHeap.top();
    }
    return (minHeap.top() + maxHeap.top()) / 2.0;
  }
};

int main() {
  MedianFinder medianFinder;
  vector<string> input = {"MedianFinder", "addNum", "addNum",
                          "findMedian",   "addNum", "findMedian"};
  vector<vector<int>> params = {{}, {1}, {2}, {}, {3}, {}};

  for (int i = 0; i < input.size(); i++) {
    string op = input[i];
    vector<int> param = params[i];

    if (op == "MedianFinder") {
      medianFinder = MedianFinder();
    } else if (op == "addNum") {
      medianFinder.addNum(param[0]);
    } else if (op == "findMedian") {
      double median = medianFinder.findMedian();
      cout << median << " ";
      cout << endl;
    }
  }
}
