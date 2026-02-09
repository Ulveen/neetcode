#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int index;
  int distance;

  Node(int index, int distance) : index(index), distance(distance) {}
};

class Compare {
public:
  bool operator()(Node a, Node b) { return a.distance > b.distance; }
};

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<Node, vector<Node>, Compare> pq;

    for (int i = 0; i < points.size(); i++) {
      Node node = Node(i, pow(points[i][0], 2) + pow(points[i][1], 2));
      pq.push(node);
    }

    vector<vector<int>> result;
    for (int i = 0; i < k; i++) {
      if (pq.empty()) {
        break;
      }
      result.push_back(points[pq.top().index]);
      pq.pop();
    }

    return result;
  }
};

int main() {
  vector<vector<int>> points = {{0, 1}, {1, 0}};
  int k = 2;

  vector<vector<int>> result = Solution().kClosest(points, k);
  for (vector<int> v : result) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
