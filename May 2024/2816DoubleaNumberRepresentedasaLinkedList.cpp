#include "./bits-stdc++.h";
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
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *ptr = head;
        ListNode *prev = nullptr;
        while (ptr != nullptr)
        {
            int currentMul = ptr->val * 2;
            int carry;
            if (currentMul >= 10)
            {
                carry = currentMul / 10;
                if (prev == nullptr)
                {
                    ListNode *newNode = new ListNode(carry);
                    newNode->next = head;
                    head = newNode;
                    ptr->val = currentMul % 10;
                }
                else
                {
                    prev->val += carry;
                    ptr->val = currentMul % 10;
                }
            }
            else
            {
                ptr->val = currentMul;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};
int main()
{
    return 0;
}