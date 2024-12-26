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
    void traversleft(TreeNode *node, string &left)
    {
        if (!node)
            left += "n";
        left += to_string(node->val);
        traversleft(node->left, left);
        traversleft(node->right, left);
    }

    void traversright(TreeNode *node, string &right)
    {
        if (!node)
            right += "n";
        right += to_string(node->val);
        traversright(node->right, right);
        traversright(node->left, right);
    }

    bool isSymmetric(TreeNode *root)
    {
        string left;
        traversleft(root->left, left);
        string right;
        traversright(root->right, right);
        cout << "left: " << left << "\n"
             << "rigt: " << right << '\n';
        return left == right;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    bool ans = Solution().isSymmetric(root);
    cout << (ans ? "yes\n" : "no\n");
}