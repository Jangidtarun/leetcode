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

TreeNode *create_tree(TreeNode *s, vector<int> &v, int i)
{
    if (!s)
    {
        s = new TreeNode(v[i++]);
        s->left = new TreeNode(v[i++]);
        s->right = new TreeNode(v[i++]);
        return s;
    }
    s->left = create_tree(s->left, v, i);
    s->right = create_tree(s->left, v, i);
    return s;
}

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return create_tree(nullptr, nums, 0);
    }
};