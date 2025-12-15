#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  char c;
  int count;
  int readyTime;

  Node(char c, int count) : c(c), count(count) {}
};

class Compare {
public:
  bool operator()(Node a, Node b) { return a.count < b.count; }
};

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int counts[26] = {0};
    for (char c : tasks) {
      counts[c - 'A']++;
    }

    priority_queue<Node, vector<Node>, Compare> pq;

    for (int i = 0; i < 26; i++) {
      if (counts[i] > 0) {
        pq.push({(char)(i + 'A'), counts[i]});
      }
    }

    queue<Node> q;
    int time = 0;

    while (!pq.empty() || !q.empty()) {
      time++;

      if (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        curr.count--;

        if (curr.count > 0) {
          curr.readyTime = time + n;
          q.push(curr);
        }
      }

      if (!q.empty() && q.front().readyTime == time) {
        pq.push(q.front());
        q.pop();
      }
    }

    return time;
  }
};

int main() {
  vector<char> tasks = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
  int n = 4;
  int result = Solution().leastInterval(tasks, n);

  cout << result << endl;
}
