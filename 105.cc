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
    unordered_map<int, int> ino;
    TreeNode *buildutil(vector<int> &preorder, vector<int> &inorder, pair<int, int> p, pair<int, int> i)
    {
        if (p.first > p.second or i.first > i.second)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[p.first]);
        int mid = ino[root->val];
        int nelm = mid - i.first;
        root->left = buildutil(preorder, inorder, {p.first + 1, p.first + nelm}, {i.first, mid - 1});
        root->right = buildutil(preorder, inorder, {p.first + nelm + 1, p.second}, {mid + 1, i.second});
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            ino[inorder[i]] = i;
        TreeNode *ans = buildutil(preorder, inorder, {0, preorder.size() - 1}, {0, inorder.size() - 1});
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