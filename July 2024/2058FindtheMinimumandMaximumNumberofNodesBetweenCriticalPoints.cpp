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

ListNode *createLinkedList(const std::vector<int> &values)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int val : values)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

vector<int> nodesBetweenCriticalPointsShort(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
    {
        return {-1, -1};
    }

    ListNode *curr = head->next;
    ListNode *prev = head;
    int currentIndex = 1; // Start from the second node
    int criticalPoint = -1;
    int minDistance = INT_MAX;
    int firstCriticalPoint = -1, lastCriticalPoint = -1;

    while (curr->next != nullptr)
    {
        if ((curr->val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val))
        {
            if (firstCriticalPoint == -1)
            {
                firstCriticalPoint = currentIndex;
            }
            else
            {
                minDistance = min(minDistance, currentIndex - criticalPoint);
            }

            criticalPoint = currentIndex;
            lastCriticalPoint = currentIndex;
        }

        prev = curr;
        curr = curr->next;
        currentIndex++;
    }

    if (minDistance == INT_MAX)
    {
        return {-1, -1};
    }

    return {minDistance, lastCriticalPoint - firstCriticalPoint};
}

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{

    if (!head || !head->next || !head->next->next)
    {
        return {-1, -1};
    }

    ListNode *curr = head;
    ListNode *prev = nullptr;

    int currentIndex = 0;
    int criticalPoint = 0;
    bool cpFound = false;

    int minDistance = INT_MAX;
    int maxDistance = INT_MIN;

    int firstCriticalPoint = INT_MAX, lastCriticalPoint = INT_MIN;

    while (curr != nullptr)
    {

        if (prev != nullptr && curr->next != nullptr)
        {
            if (curr->val > prev->val && curr->val > curr->next->val)
            {
                if (cpFound)
                {
                    minDistance = min(minDistance, currentIndex - criticalPoint);
                }
                if (!cpFound)
                {
                    firstCriticalPoint = min(currentIndex, firstCriticalPoint);
                }

                criticalPoint = currentIndex;
                cpFound = true;
                lastCriticalPoint = max(lastCriticalPoint, currentIndex);
            }

            if (curr->val < prev->val && curr->val < curr->next->val)
            {
                if (cpFound)
                {
                    minDistance = min(minDistance, currentIndex - criticalPoint);
                }
                if (!cpFound)
                {
                    firstCriticalPoint = min(currentIndex, firstCriticalPoint);
                }
                criticalPoint = currentIndex;
                cpFound = true;
                lastCriticalPoint = max(lastCriticalPoint, currentIndex);
            }
        }
        prev = curr;
        curr = curr->next;
        currentIndex++;
    }

    if (minDistance == INT_MAX)
    {
        minDistance = -1;
    }

    if (firstCriticalPoint == INT_MAX || lastCriticalPoint == INT_MIN)
    {
        maxDistance = -1;
        return {minDistance, maxDistance};
    }
    if (firstCriticalPoint == lastCriticalPoint)
    {
        return {-1, -1};
    }

    return {minDistance, lastCriticalPoint - firstCriticalPoint};
}

int main()
{
    std::vector<int> values = {2, 2, 1, 3};
    ListNode *head = createLinkedList(values);

    vector<int> res = nodesBetweenCriticalPoints(head);
    cout << res[0] << " " << res[1];

    return 0;
}