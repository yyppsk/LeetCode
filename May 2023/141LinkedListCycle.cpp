#include <iostream>

using namespace std;

// Definition for singly-linked list
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // TODO: Implement cycle detection algorithm
        ListNode *current = head;
        while (current != NULL)
        {
            if (current->val == 100005)
                return true;
            current->val = 100005;
            current = current->next;
        }
        return false;
    }
    void print(ListNode *head)
    {
        ListNode *current = head;
        while (current != NULL)
        {
            cout << current->val << " ";
            current = current->next;
        }
    }
};

int main()
{
    // Create a linked list with 3 nodes
    //[3,2,0,-4]
    int arr[100] = {2672, 58126, -56709, 46298, -36483, 20486, -97546, -20642, -87240, 53092,
                    -98595, 52275, -17462, -69426, -94510, 8899, 45928, 42595, 3330, 431,
                    -68047, -38623, -26928, -12129, -57391, 16656, 83225, -83521, 38311, -16366,
                    -30784, 12346, 97017, -2366, -20556, -58456, 83141, -14397, -13056, -17650,
                    1616, -71873, 31920, -30280, -77501, -54602, -28996, -36985, -21647, 63928,
                    -57083, -27035, -26458, 23335, 47112, -25252, -12195, 24785, 71589, 9059,
                    -19323, -92477, -38390, 48450, 81484, 16124, -75685, -31249, -91429, 97734,
                    25033, 68623, 96584, 28318, -98768, 23490, -68202, 73477, 8255, 523,
                    55399, 41371, -10249, 64736, -30345, -10005, -94934, 78815, 29292, 98619,
                    -64599, -35519, -69909, 18002, -64881, -27734, -31280, 10985, -87122, 25975};

    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    // Set the last node's next pointer to the head to create a cycle
    node3->next = node1;

    // Create an instance of the Solution class and test the hasCycle method
    Solution sol;
    bool hasCycle = sol.hasCycle(head);
    cout << "Does the linked list have a cycle? " << (hasCycle ? "Yes" : "No") << endl;
    // sol.print(head);
    return 0;
}
