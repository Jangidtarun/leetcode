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

ListNode *deleteMiddle(ListNode *head)
{
    if (head->next == nullptr)
        return nullptr;
    ListNode *slow = head, *fast = head->next, *n = nullptr;
    while (fast and fast->next)
    {
        n = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast == nullptr){
        n->next = slow->next;
        // return head;
    }

    else if(fast->next = nullptr){
        slow->next = slow->next->next;
        // return head;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode *ans = deleteMiddle(head);
    for (ListNode *current = head; current != nullptr; current = current->next)
        cout << current->val << " ";
    cout << endl;
}