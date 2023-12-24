#include <bits/stdc++.h>
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

class Solution
{
public:
    int dfs(TreeNode *node, int depth)
    {
        if (node == nullptr)
            return depth;
        int leftdepth = depth + 1, rightdepth = depth + 1;
        leftdepth = dfs(node->left, leftdepth);
        rightdepth = dfs(node->right, rightdepth);
        return max(leftdepth, rightdepth);
    }

    int maxDepth(TreeNode *root)
    {
        return dfs(root, 0);
    }
};

int main()
{
    Solution sol = Solution();
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int ans = sol.maxDepth(root);
    cout << ans << endl;
}