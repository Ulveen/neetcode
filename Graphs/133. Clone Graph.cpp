#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

void visualize(Node *node) {
  if (!node)
    return;
  queue<Node *> nodes;
  unordered_set<int> visited;
  nodes.push(node);
  visited.insert(node->val);

  while (!nodes.empty()) {
    Node *curr = nodes.front();
    nodes.pop();

    printf("Node: %d, neighbors:", curr->val);

    for (Node *neighbor : curr->neighbors) {
      printf(" %d", neighbor->val);
      if (visited.find(neighbor->val) == visited.end()) {
        nodes.push(neighbor);
        visited.insert(neighbor->val);
      }
    }

    cout << endl;
  }
}

class Solution {
private:
  unordered_map<int, Node *> mapping;
  void bfs(Node *curr) {
    if (mapping.find(curr->val) != mapping.end()) {
      return;
    }
    mapping[curr->val] = new Node(curr->val);
    for (Node *neighbor : curr->neighbors) {
      if (mapping.find(neighbor->val) == mapping.end()) {
        bfs(neighbor);
      }
      mapping[curr->val]->neighbors.push_back(mapping[neighbor->val]);
    }
  }

public:
  Node *cloneGraph(Node *adjList) {
    if (!adjList) {
      return nullptr;
    }
    bfs(adjList);
    return mapping[adjList->val];
  }
};

int main() {
  vector<vector<int>> neighborList = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
  vector<Node *> nodes;

  for (int i = 0; i < neighborList.size(); i++) {
    nodes.push_back(new Node(i + 1));
  }

  for (int i = 0; i < neighborList.size(); i++) {
    for (int j = 0; j < neighborList[i].size(); j++) {
      nodes[i]->neighbors.push_back(nodes[neighborList[i][j] - 1]);
    }
  }

  cout << "Original" << endl;
  visualize(nodes[0]);

  Node *adjList = nodes[0];
  Node *result = Solution().cloneGraph(adjList);

  cout << "Result" << endl;
  visualize(result);
}
