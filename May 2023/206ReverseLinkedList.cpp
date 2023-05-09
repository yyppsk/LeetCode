#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *chase = nullptr, *current = head;
    while (current != nullptr)
    {
        ListNode *forward = current->next;
        current->next = chase;
        chase = current;
        current = forward;
    }
    return chase;
}
int main()
{
    // Creating the linked list with the values [1,2,3,4,5]
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = reverseList(head);
    printLinkedList(head);
    return 0;
}
