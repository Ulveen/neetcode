#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int values[] = {
    0,
    1, 2,
    3, 4, -1, -1,
    7, -1, -1, 10, -1, -1, -1, -1,
    15, -1, -1, -1, -1, -1, -1, 22};
const int n = sizeof(values) / sizeof(int);

TreeNode *init(int idx)
{
    if (idx > n - 1 || values[idx] == -1)
    {
        return nullptr;
    }
    TreeNode *curr = new TreeNode(values[idx]);
    curr->left = init(2 * idx + 1);
    curr->right = init(2 * idx + 2);

    return curr;
}

class Solution
{
private:
    int maxDiameter = 0;
    int iter(TreeNode *root, int depth)
    {
        if (!root)
        {
            return depth - 1;
        }

        int leftHeight = iter(root->left, depth + 1);
        int rightHeight = iter(root->right, depth + 1);

        int diameter = leftHeight + rightHeight - 2 * depth;
        maxDiameter = max(maxDiameter, diameter);

        return max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        iter(root, 0);
        return maxDiameter;
    }
};

int main()
{
    TreeNode *root = init(0);
    int result = Solution().diameterOfBinaryTree(root);
    cout << result;
}