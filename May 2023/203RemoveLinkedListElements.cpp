#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *current = head;
        ListNode *tail = nullptr;

        while (current != nullptr)
        {
            if (current->val == val)
            {
                if (current == head)
                {
                    head = current->next;
                }
                else
                {
                    tail->next = current->next;
                }
                ListNode *dummy = current;
                current = current->next;
                delete dummy;
            }
            else
            {
                // Update the tail pointer to the current node
                tail = current;
                // Move to the next node
                current = current->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    return 0;
}
