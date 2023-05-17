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
// First I wanna traverse the whole list to take my end pointer towards the end and try a data structure based approach
int pairSum(ListNode *head)
{
    vector<int> arr;
    ListNode *current = head;
    while (current != nullptr)
    {
        arr.push_back(current->val);
        current = current->next;
    }
    int start = 0, end = arr.size() - 1;
    int n = arr.size();
    int maxim = INT_MIN;
    while (start <= (n / 2 - 1))
    {
        maxim = max(maxim, arr[start] + arr[end]);
        start++, end--;
    }
    return maxim;
}

int main()
{
    // Create the linked list
    ListNode *head = new ListNode(8);
    head->next = new ListNode(9);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next = new ListNode(2);

    // Print the linked list values
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
    // Free memory
    current = head;
    cout << pairSum(current);
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
