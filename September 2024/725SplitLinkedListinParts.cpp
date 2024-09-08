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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 0;

        while (curr)
        {
            len += 1;
            curr = curr->next;
        }

        int atleast = len / k;
        int extras = len % k;

        vector<ListNode *> result(k, nullptr);

        curr = head;

        ListNode *prev = nullptr;

        for (int i = 0; curr != nullptr && i < k; i++)
        {
            result[i] = curr;

            for (int j = 1; j <= atleast + (extras > 0 ? 1 : 0); j++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            extras--;
        }

        return result;
    }
};
int main()
{
    return 0;
}