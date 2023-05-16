#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// Definition for singly-linked list
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
    if (head == nullptr)
    {
        return head;
    }
    int jump = 0;
    ListNode *current = head;
    ListNode *previous = nullptr;
    while (current != nullptr)
    {
        // cout << "Fast on " << fast->val << " Node & Slow = " << endl;
        if (jump == 1)
        {
            swap(current->val, previous->val);
            // previous = current;
            // current = current->next;
            jump = -1;
        }
        else
        {
            // cout << "Moving Fast to Next node " << fast->val << " to " << fast->next->val << endl;
            previous = current;
            current = current->next;
            jump++;
        }
    }

    return head;
}

int main()
{
    // Create the linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    // Print the linked list values
    ListNode *current = swapPairs(head);
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
    // Free memory
    current = head;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
