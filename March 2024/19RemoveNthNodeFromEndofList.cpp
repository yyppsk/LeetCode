#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *current = head;
    int counter = 0;
    while (current != nullptr)
    {
        current = current->next;
        counter++;
    }
    int toRemove = counter - n;

    current = head;
    ListNode *ptrTail = nullptr;

    for (int i = 1; i <= max(toRemove, 1); i++)
    {
        ptrTail = current;
        current = current->next;
    }
    if (toRemove == 0)
    {
        // When deleating first node
        delete ptrTail;
        head = current;
    }
    else
    {
        ptrTail->next = current->next;
        delete current;
    }

    return head;
}
int main()
{
    ListNode *head = nullptr;
    ListNode *node1;
    ListNode *node2;
    ListNode *node3;
    ListNode *node4;
    ListNode *node5;

    // Creating nodes
    node1 = new ListNode(1);
    node2 = new ListNode(2);

    // Constructing the linked list
    head = node1;
    node1->next = node2;
    node2->next = nullptr;

    // Traversing and printing the linked list
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << "\n";

    ListNode *changed = removeNthFromEnd(head, 2);

    while (changed != nullptr)
    {
        cout << changed->val << " ";
        changed = changed->next;
    }
    return 0;
}