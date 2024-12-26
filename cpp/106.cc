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

TreeNode *construct_tree(vector<int> &nodes, int i, int n)
{
    TreeNode *root = nullptr;
    if (i < n)
    {
        root = new TreeNode(nodes[i]);
        root->left = construct_tree(nodes, 2 * i + 1, n);
        root->right = construct_tree(nodes, 2 * i + 2, n);
    }
    return root;
}

void preordertraverse(TreeNode *node)
{
    if (!node)
        return;
    cout << node->val << "\n";
    preordertraverse(node->left);
    preordertraverse(node->right);
}

class Solution
{
public:
    unordered_map<int, int> m;
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, pair<int, int> i, pair<int, int> p)
    {
        if (i.first > i.second or p.first > p.second)
            return nullptr;

        TreeNode *root = new TreeNode(postorder.back());
        int ind = m[root->val];
        int nleftelem = ind - i.first;
        int nrighelem = i.second - ind;
        root->right = helper(inorder, postorder, {ind + 1, i.second}, {p.second - nrighelem, p.second - 1});
        root->left = helper(inorder, postorder, {i.first, ind - 1}, {p.first, p.first + nleftelem - 1});
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        TreeNode *ans = helper(inorder, postorder, {0, inorder.size() - 1}, {0, postorder.size() - 1});
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    TreeNode *t = construct_tree(v, 0, v.size());
    vector<int> preorer = {3, 9, 20, 5, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *ans = Solution().buildTree(preorer, inorder);
    preordertraverse(ans);
}