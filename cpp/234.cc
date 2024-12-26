#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    if (!head or !head->next)
        return true;
    stack<int> s;
    while (head)
    {
        if (s.empty())
            s.push(head->val);
        else
        {
            if (s.top() == head->val)
                s.pop();
            else
                s.push(head->val);
        }
        head = head->next;
    }
    return s.empty();
}

int main()
{
    ListNode *h = new ListNode(1);
    h->next = new ListNode(3);
    h->next->next = new ListNode(4);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(1);
    bool ans = isPalindrome(h);
    cout << (ans ? "yes\n" : "no\n");
}