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

ListNode *revlist(ListNode *head)
{
    ListNode *ans = nullptr;
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        ListNode *in = new ListNode(tmp->val);
        in->next = ans;
        ans = in;
    }
    return ans;
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t1 = list1;
        ListNode *t2 = list2;
        ListNode *ans = nullptr;
        while (t1 != nullptr and t2 != nullptr)
        {
            int minval = INT_MAX;
            if (t1->val < t2->val)
            {
                minval = t1->val;
                t1 = t1->next;
            }
            else
            {
                minval = t2->val;
                t2 = t2->next;
            }
            ListNode *tmp = new ListNode(minval);
            tmp->next = ans;
            ans = tmp;
        }
        while (t1 != nullptr)
        {
            ListNode *tmp = new ListNode(t1->val);
            tmp->next = ans;
            ans = tmp;
            t1 = t1->next;
        }
        while (t2 != nullptr)
        {
            ListNode *tmp = new ListNode(t2->val);
            tmp->next = ans;
            ans = tmp;
            t2 = t2->next;
        }
        ans = revlist(ans);
        return ans;
    }
};