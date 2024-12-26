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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *ans = nullptr;
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        for (; tmp1 != nullptr and tmp2 != nullptr; tmp1 = tmp1->next, tmp2 = tmp2->next)
        {
            int val = tmp1->val + tmp2->val + carry;
            carry = val / 10;
            val %= 10;
            ListNode *tmp = new ListNode(val);
            tmp->next = ans;
            ans = tmp;
        }
        for (; tmp1 != nullptr; tmp1 = tmp1->next)
        {
            int val = tmp1->val + carry;
            carry = val / 10;
            val %= 10;
            ListNode *tmp = new ListNode(val);
            tmp->next = ans;
            ans = tmp;
        }
        for (; tmp2 != nullptr; tmp2 = tmp2->next)
        {
            int val = tmp2->val + carry;
            carry = val / 10;
            val %= 10;
            ListNode *tmp = new ListNode(val);
            tmp->next = ans;
            ans = tmp;
        }
        if (carry != 0)
        {
            ListNode *tmp = new ListNode(carry);
            tmp->next = ans;
            ans = tmp;
        }
        ans = revlist(ans);
        return ans;
    }
};

void printlist(ListNode *head)
{
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next)
        cout << tmp->val << "->";
    cout << "null\n";
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol = Solution();
    ListNode *ans = sol.addTwoNumbers(l1, l2);
    printlist(l1);
    printlist(l2);
    printlist(ans);
}