#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> h;
        Node *curr = head;
        while (curr)
        {
            h[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr)
        {
            h[curr]->next = h[curr->next];
            h[curr]->random = h[curr->random];
            curr = curr->next;
        }
        return h[head];
    }
};