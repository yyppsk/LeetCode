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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *l1start = list1;
    ListNode *l1end = list1;

    int i = 0;
    while (i != a - 1)
    {
        l1start = l1start->next;
        i++;
    }

    i = 0;

    while (i != b + 1)
    {
        l1end = l1end->next;
        i++;
    }

    ListNode *l2end = list2;

    while (l2end->next != nullptr)
    {
        l2end = l2end->next;
    }

    l1start->next = list2;

    l2end->next = l1end;

    return list1;
}

// Utility function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating list1
    ListNode *list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);

    // Creating list2
    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    // Merge lists
    int a = 3, b = 4;
    list1 = mergeInBetween(list1, a, b, list2);

    // Print the merged list
    printList(list1);

    return 0;
}