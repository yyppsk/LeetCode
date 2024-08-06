#include <bits/bits-stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        vector<int> B;
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        while (!ptrB)
        {
            B.push_back(ptrB->val);
            ptrB->val = -1;
            ptrB = ptrB->next;
        }
        while (!ptrA)
        {
            if (ptrA->val == -1)
            {
                break;
            }
            ptrA = ptrA->next;
        }
        ptrB = headB;
        int i = 0;
        while (!ptrB)
        {
            ptrB->val = B[i];
            i++;
        }
        return ptrA;
    }
};
int main()
{
    return 0;
}