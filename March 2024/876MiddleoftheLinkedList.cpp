#include <bits/stdc++.h>
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

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *ptr = head;
        int count = 0;
        while (ptr != nullptr)
        {
            count += 1;
            ptr = ptr->next;
        }
        int mid = count / 2;
        ptr = head;
        for (int i = 0; i < mid; i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
};
int main()
{
    return 0;
}