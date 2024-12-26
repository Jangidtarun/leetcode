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

ListNode *swapPairs(ListNode *head)
{
  ListNode *curr = head;
  while (curr != NULL and curr->next != NULL)
  {

    ListNode *tmp = curr->next;
    curr->next = tmp->next;
    tmp->next = curr;
    if (curr == head)
      head = tmp;
    curr = curr->next;
  }
  return head;
}

void printlist(ListNode *head)
{
  ListNode *curr = head;
  cout << curr->val;
  curr = curr->next;
  while (curr != nullptr)
  {
    cout << " -> " << curr->val;
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  printlist(head);

  // ListNode *tmp = head->next;
  // // cout << "tmp: " << tmp->val << endl;
  // head->next = tmp->next;
  // printlist(head);
  // cout << "head: " << head->val << " head.next: " << head->next->val << endl;
  // cout << "tmp: " << tmp->val << " tmp.next: " << tmp->next->val << endl;
  // tmp->next = head;
  // cout << "head: " << head->val << " head.next: " << head->next->val << endl;
  // cout << "tmp: " << tmp->val << " tmp.next: " << tmp->next->val << endl;
  // head = tmp;

  ListNode *newhead = swapPairs(head);
  printlist(newhead);
}