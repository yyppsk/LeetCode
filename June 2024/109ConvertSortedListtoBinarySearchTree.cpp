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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return new TreeNode(head->val);
        }

        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        ListNode *slowPrev = nullptr;

        while (fastPtr != nullptr && fastPtr->next != nullptr)
        {
            slowPrev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        TreeNode *root = new TreeNode(slowPtr->val);
        slowPrev->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slowPtr->next);

        return root;
    }
};
int main()
{

    return 0;
}