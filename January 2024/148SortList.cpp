#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        vector<int> storage;
        for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            storage.push_back(ptr->val);
        }
        sort(storage.begin(), storage.end());

        int cursor = 0;
        for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        {
            ptr->val = storage[cursor++];
        }
        return head;
    }
};
int main()
{
    return 0;
}