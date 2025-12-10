#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  string result = "";
  int nullCount = 0;

private:
  void inorder(TreeNode *root) {
    if (!root) {
      nullCount++;
      return;
    }
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) {
      return result;
    }
    inorder(root);
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) { return nullptr; }
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

void preorder(TreeNode *node) {
  if (!node)
    return;
  preorder(node->left);
  cout << node->val << " ";
  preorder(node->right);
}

int main() {
  vector<int> values = {1, 2, 3, NULL_NODE, NULL_NODE, 4, 5};
  TreeNode *root = buildBST(values, 0);

  Codec codec = Codec();
  string serialized = codec.serialize(root);

  cout << serialized << endl;

  TreeNode *deserialized = codec.deserialize(serialized);

  preorder(deserialized);
  cout << endl;
}
