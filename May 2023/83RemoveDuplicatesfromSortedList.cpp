#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
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
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *current = head;
    while (current->next != nullptr)
    {
        if (current->val == current->next->val)
        {
            ListNode *todelete = current->next;
            current->next = todelete->next;
            delete todelete;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}
int main()
{
    return 0;
}