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
private:
    TreeNode *helper(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return nullptr;
        int i = start;
        for (int j = start; j < end; j++)
        {
            if (nums[i] < nums[j])
                i = j;
        }
        TreeNode *curr = new TreeNode(nums[i]);
        curr->left = helper(nums, start, i);
        curr->right = helper(nums, i + 1, end);
        return curr;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;
        TreeNode *root = helper(nums, 0, nums.size());
        return root;
    }
};

int main()
{
    vector<int> v = {3, 2, 1, 6, 0, 5};
    TreeNode* root = Solution().constructMaximumBinaryTree(v);
}