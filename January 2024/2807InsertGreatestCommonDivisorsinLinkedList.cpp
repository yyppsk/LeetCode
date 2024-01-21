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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *ptr = head;
        while (ptr->next != nullptr)
        {
            int value = __gcd(ptr->val, ptr->next->val);
            ListNode *temp = new ListNode(value);
            ListNode *runner = ptr;
            ptr = ptr->next;
            temp->next = ptr;
            runner->next = temp;
        }
        return head;
    }
};
int main()
{
    return 0;
}