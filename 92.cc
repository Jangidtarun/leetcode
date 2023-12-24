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

void printlist(ListNode *head)
{
    for (ListNode *tmp = head; tmp != nullptr; tmp = tmp->next)
        cout << tmp->val << "->";
    cout << "null\n";
}

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *d = new ListNode(INT_MIN);
        d->next = head;
        ListNode *tmpleft, *tmpright, *tmp = d;
        while (tmp)
        {
            left--;
            right--;
            if (!left)
                tmpleft = tmp;
            if (!right)
                tmpright = tmp;
            tmp = tmp->next;
        }

        ListNode *end = tmpright->next->next;
        ListNode *newh = tmpleft->next;
        tmpleft->next = nullptr;
        tmpright->next->next = nullptr;
        newh = revlist(newh);
        tmpleft->next = newh;

        while (newh->next)
            newh = newh->next;
        newh->next = end;

        return d->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printlist(head);
    int left = 2, right = 4;
    ListNode *ans = Solution().reverseBetween(head, left, right);
    cout << "ans: ";
    printlist(ans);
}