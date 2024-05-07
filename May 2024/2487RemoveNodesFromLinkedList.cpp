#include <bits/bits-stdc++.h>
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

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode temp(INT_MAX);
        vector<ListNode *> stack{&temp};
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            while (stack.back()->val < ptr->val)
            {
                stack.pop_back();
            }
            stack.back()->next = ptr;
            stack.push_back(ptr);
        }
        return temp.next;
    }
};
int main()
{
    return 0;
}