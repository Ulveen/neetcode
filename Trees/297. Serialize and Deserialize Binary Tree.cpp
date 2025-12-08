#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string result = "";

    if (!root) {
      return "";
    }

    queue<pair<int, TreeNode *>> queue;
    int count = 0;
    queue.push({0, root});

    while (!queue.empty()) {
      pair<int, TreeNode *> temp = queue.front();
      queue.pop();

      int idx = temp.first;
      TreeNode *node = temp.second;

      while (count++ < idx) {
        result += ";n";
      }

      if (result.length() > 0) {
        result += ";";
      }

      result += to_string(node->val);
      if (node->left) {
        queue.push({idx * 2 + 1, node->left});
      }
      if (node->right) {
        queue.push({idx * 2 + 2, node->right});
      }
    }

    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.length() == 0) {
      return nullptr;
    }
    stringstream ss(data);
    string token;

    unordered_map<int, TreeNode *> um;
    int idx = 0;

    while (getline(ss, token, ';')) {
      if (token != "n") {
        TreeNode *node = new TreeNode(stoi(token));
        um[idx] = node;

        if (idx > 0) {
          int parentIdx = (idx - 1) / 2;
          if (idx % 2 == 1) {
            um[parentIdx]->left = node;
          } else {
            um[parentIdx]->right = node;
          }
        }
      }
      idx++;
    }

    return um[0];
  }
};

const int NULL_NODE = INT_MIN;

TreeNode *buildBST(vector<int> &values, int idx) {
  if (idx >= values.size() || values[idx] == NULL_NODE) {
    return nullptr;
  }
  TreeNode *node = new TreeNode(values[idx]);
  node->left = buildBST(values, idx * 2 + 1);
  node->right = buildBST(values, idx * 2 + 2);

  return node;
}

void inorder(TreeNode *node) {
  if (!node)
    return;
  inorder(node->left);
  cout << node->val << " ";
  inorder(node->right);
}

int main() {
  vector<int> values = {1, 2, NULL_NODE, 4, 5};
  TreeNode *root = buildBST(values, 0);

  Codec codec = Codec();
  string serialized = codec.serialize(root);

  cout << serialized << endl;

  TreeNode *deserialized = codec.deserialize(serialized);

  inorder(deserialized);
  cout << endl;
}
