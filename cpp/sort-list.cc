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

void swapNodes(ListNode **head, int x, int y)
{
    if (x == y)
        return;

    ListNode *prevX = nullptr, *currX = *head;
    while (currX and currX->val != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    ListNode *prevY = nullptr, *currY = *head;
    while (currY and currY->val != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == nullptr || currY == nullptr)
        return;

    if (prevX != nullptr)
        prevX->next = currY;
    else // Else make y as new head
        *head = currY;

    if (prevY != nullptr)
        prevY->next = currX;
    else // Else make x as new head
        *head = currX;

    ListNode *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

ListNode *sortList(ListNode *head)
{

    for (auto current_first = head; current_first != nullptr; current_first = current_first->next)
    {
        ListNode *minval_node = current_first;
        for (auto curr_min = current_first; curr_min != nullptr; curr_min = curr_min->next)
        {
            if (curr_min->val < minval_node->val)
                minval_node = curr_min;
        }

        swapNodes(&head, current_first->val, minval_node->val);
    }
    return head;
}

int main()
{
    ListNode *ll = new ListNode(4);
    ll->next = new ListNode(2);
    ll->next->next = new ListNode(1);
    ll->next->next->next = new ListNode(3);

    ListNode *sorted = sortList(ll);
    for (auto it = sorted; it != nullptr; it = it->next)
        cout << it->val << " ";
    cout << endl;
}