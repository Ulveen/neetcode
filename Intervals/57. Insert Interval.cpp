#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();
    vector<vector<int>> result;

    if (intervals.empty()) {
      result.push_back(newInterval);
      return result;
    }

    int state = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
      vector<int> interval = intervals[i];

      // continue search
      if (interval[1] < newInterval[0]) {
        result.push_back(interval);
        continue;
      }

      idx = i;

      // insert newInterval
      if (interval[0] > newInterval[1]) {
        state = 1;
        result.push_back(newInterval);
      }

      // ignore newInterval
      else if (interval[0] <= newInterval[0] && interval[1] >= newInterval[1]) {
        state = 2;
      }

      // merge intervals
      else {
        state = 3;
      }
      break;
    }

    if (state == 0) {
      result.push_back(newInterval);
      return result;
    }

    if (state <= 2) {
      while (idx < n) {
        result.push_back(intervals[idx++]);
      }
      return result;
    }

    int startIdx = idx, endIdx = idx;
    while (endIdx < n && intervals[endIdx][1] < newInterval[1]) {
      endIdx++;
    }

    if (endIdx == n || intervals[endIdx][0] > newInterval[1]) {
      endIdx--;
    }

    int minVal = min(intervals[startIdx][0], newInterval[0]);
    int maxVal = max(intervals[endIdx][1], newInterval[1]);

    result.push_back({minVal, maxVal});
    while (++endIdx < n) {
      result.push_back(intervals[endIdx]);
    }

    return result;
  }
};

int main() {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};

  vector<vector<int>> result = Solution().insert(intervals, newInterval);
  for (auto v : result) {
    for (int num : v) {
      cout << num << " ";
    }
    cout << endl;
  }
}
