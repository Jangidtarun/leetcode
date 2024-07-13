#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> sorted_tree;

void inorder_bst(TreeNode* curr){
    if(!curr) return;
    inorder_bst(curr->left);
    sorted_tree.push_back(curr->val);
    inorder_bst(curr->right);
}

TreeNode* sorted_to_bst(int start, int end){
    if(start > end) return nullptr;

    int mid = sorted_tree[(start+end)/2];
    TreeNode* root = new TreeNode(mid);

    root->left = sorted_to_bst(start, mid-1);
    root->right = sorted_to_bst(mid+1, end);

    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    inorder_bst(root);
    for(auto &val: sorted_tree)
        cout << val << endl;
    int n = sorted_tree.size();
    TreeNode* ans = sorted_to_bst(0,n-1);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    // inorder_bst(root);

    TreeNode* ans = balanceBST(root);
}