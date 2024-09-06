#include <bits/bits-stdc++.h>
using namespace std;
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> vals(nums.begin(), nums.end());

        ListNode *tail = nullptr;
        for (ListNode *ptr = head; ptr != nullptr;)
        {
            if (vals.count(ptr->val))
            {
                if (ptr == head)
                {
                    ListNode *temp = ptr;
                    head = head->next;
                    temp->next = nullptr;
                    ptr = head;
                }
                else
                {
                    ListNode *temp = tail->next;
                    ptr = ptr->next;
                    tail->next = ptr;
                    temp->next = nullptr;
                }
            }
            else
            {
                tail = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};
int main()
{
    return 0;
}