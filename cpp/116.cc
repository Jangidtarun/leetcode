#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
private:
    int row = 0;
    void bfs(Node *curr)
    {
        if (!curr)
            return;
        queue<Node *> q;
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        row++;
        Node *last = nullptr;
        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();
            cout << "row " << row << ": " << t->val << "\n";
            t->next = last;
            last = t;
            bfs(t);
            row--;
        }
    }

public:
    Node *connect(Node *root)
    {
        bfs(root);
        return root;
    }
};

int main()
{
    cout << "hellow world\n";
    return 0;
}