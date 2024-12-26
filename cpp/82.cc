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

void printlist(ListNode *a)
{
    while (a)
    {
        cout << a->val << "\n";
        a = a->next;
    }
}

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto tmp = head;
        ListNode* ans = nullptr;
        while (tmp)
        {
            int count = 0;
            int val = tmp->val;
            auto counter = tmp;
            while (counter and counter->val == val)
            {
                counter = counter->next;
                count++;
            }
            if (count == 1)
            {
                ListNode* p = new ListNode(tmp->val);
                p->next = ans;
                ans = p;
            }
            tmp = tmp->next;
        }
        ListNode* newans = nullptr;
        while (ans)
        {
            ListNode* x = new ListNode(ans->val);
            x->next = newans;
            newans = x;
            ans = ans->next;
        }
        return newans;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next = new ListNode(5);
    auto ans = Solution().deleteDuplicates(root);
    cout << "root\n";
    printlist(root);
    cout << "ans\n";
    printlist(ans);
}