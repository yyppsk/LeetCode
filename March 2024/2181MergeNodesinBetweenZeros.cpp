#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeNodes(ListNode *head)
{
    ListNode *ptr = head;
    ListNode *temp = head;

    ptr = ptr->next;
    while (ptr != nullptr)
    { // To prevent moving of temp pointer one extra node when PTR hits the last zero
        if (ptr->val == 0 && ptr->next != nullptr)
        {

            temp = temp->next;
            temp->val = 0;
        }
        temp->val += ptr->val;
        ptr = ptr->next;
    }
    temp->next = nullptr;
    return head;
}

void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

ListNode *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;

    for (int i = 1; i < n; ++i)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

int main()
{
    int arr[] = {0, 3, 1, 0, 4, 5, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode *head = createLinkedList(arr, n);

    // Print the linked list
    printList(head);
    ListNode *answer = mergeNodes(head);
    cout << "\n";
    printList(answer);
    return 0;
}