#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
// Brute Force Presorting
class Solution1
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(),
             [](auto &a, auto &b)
             {
                 return a > b;
             });
        return nums[k - 1];
    }
};
// Solution 2
class Solution2
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(),
             [](auto &a, auto &b)
             {
                 return a > b;
             });
        return nums[k - 1];
    }
};
// Solution 3
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (const auto &i : nums)
        {
            pq.push(i);
        }
        while (--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << obj.findKthLargest(nums, k);
    return 0;
}