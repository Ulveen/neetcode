#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  int result;
  int dfs(TreeNode *root) {
    if (!root)
      return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    int maxChild = max(left, right);
    int temp = max(root->val + maxChild, root->val);

    int maxCandidate = max(temp, root->val + left + right);
    result = max(result, maxCandidate);

    return temp;
  }

public:
  int maxPathSum(TreeNode *root) {
    result = INT_MIN;
    dfs(root);

    return result;
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

int main() {
  vector<int> values = {-15, 10, 20, NULL_NODE, NULL_NODE, 15, 5, -5};

  TreeNode *root = buildBST(values, 0);

  int result = Solution().maxPathSum(root);
  cout << result << endl;
}
