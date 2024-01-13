#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int currentSmallest = 0, counter = 0;
        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);

        while (!pq.empty())
        {
            if (pq.top() == 0)
            {
                pq.pop();
                // maintain no zero
            }
            else
            {
                int topElement = pq.top();
                // this step will ensure that we are having a difference for top most element
                topElement = topElement - currentSmallest; // 100 - 5 = 95

                if (topElement != 0)
                {
                    // if topElement was not able to become zero due to previous smallest
                    // we are sure this new top is next big yet smallest
                    currentSmallest = currentSmallest + topElement;
                    counter++;
                }
                pq.pop();
            }
        }
        return counter;
    }
};
int main()
{
    return 0;
}