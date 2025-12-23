#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;

  TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Codec {
private:
  void serializeHelper(string &result, TreeNode *node) {
    if (result.length() > 0) {
      result += ';';
    }
    if (!node) {
      result += 'n';
      return;
    }
    result += to_string(node->val);
    serializeHelper(result, node->left);
    serializeHelper(result, node->right);
  }

public:
  string serialize(TreeNode *root) {
    string result = "";
    serializeHelper(result, root);
    return result;
  }

  TreeNode *deserialize(string data) {
    TreeNode *root = nullptr;

    if (data.empty()) {
      return root;
    }

    stack<TreeNode *> st;
    string buffer = "";
    int nullCounter = 0;

    for (int i = 0; i < data.length(); i++) {
      if (data[i] != ';') {
        buffer += data[i];
        continue;
      }

      if (buffer[0] == 'n') {
        if (nullCounter == 1 || st.top() && st.top()->left) {
          nullCounter = 0;
          st.pop();
        } else {
          nullCounter++;
        }
      } else {
        int num = stoi(buffer);
        TreeNode *newNode = new TreeNode(num);
        if (!root) {
          root = newNode;
        } else if (nullCounter == 1 || st.top()->left) {
          st.top()->right = newNode;
          st.pop();
        } else if (nullCounter == 0) {
          st.top()->left = newNode;
        }
        nullCounter = 0;
        st.push(newNode);
      }
      buffer.clear();
    }

    return root;
  }
};

const int EMPTY = -1001;

void buildHelper(vector<int> &nums, vector<TreeNode *> &nodes, int idx) {
  if (idx >= nums.size())
    return;

  vector<TreeNode *> newNodes;
  int limit = nodes.size() * 2;

  for (int i = idx; i < nums.size(); i++) {
    int temp = i - idx;
    if (temp >= limit) {
      break;
    }
    if (nums[i] == EMPTY) {
      continue;
    }
    TreeNode *newNode = new TreeNode(nums[i]);
    TreeNode *parent = nodes[temp / 2];
    if (temp % 2 == 0) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
    newNodes.push_back(newNode);
  }

  buildHelper(nums, newNodes, idx + limit);
}

TreeNode *buildTreeFromBFS(vector<int> &nums) {
  if (nums.size() == 0) {
    return nullptr;
  }

  TreeNode *root = new TreeNode(nums[0]);
  vector<TreeNode *> temp = {root};
  buildHelper(nums, temp, 1);
  return root;
}

void preorder(TreeNode *root) {
  if (!root) {
    return;
  }
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();

    cout << curr->val << " ";
    if (curr->left) {
      q.push(curr->left);
    }
    if (curr->right) {
      q.push(curr->right);
    }
  }

  cout << endl;
}

int main() {
  vector<int> nums = {3, 2, 4, 3};
  TreeNode *root = buildTreeFromBFS(nums);
  cout << "Original: ";
  preorder(root);

  Codec c = Codec();

  string data = c.serialize(root);
  cout << "Serialized: " << data << endl;

  TreeNode *result = c.deserialize(data);
  cout << "Deserialize: ";
  preorder(result);
}
