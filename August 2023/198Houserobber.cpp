#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int stuffFinderFast(vector<int> &houses, int i, vector<int> &dp)
    {
        if (i > houses.size() - 1)
        {
            return 0;
        }
        if (i == houses.size() - 1)
            return houses[i];
        if (dp[i] != -1)
            return dp[i];

        int robAmt1 = houses[i] + stuffFinderFast(houses, i + 2, dp);
        int robAmt2 = 0 + stuffFinderFast(houses, i + 1, dp);
        return dp[i] = max(robAmt1, robAmt2);
    }
    void stuffFinder(vector<int> &houses, int &ans, int &curr, int idx)
    {
        // base case
        if (idx == houses.size())
        {
            return;
        }
        // take the house
        curr = houses[idx] + curr;
        if (idx <= houses.size() - 2)
            stuffFinder(houses, ans, curr, idx + 2);
        ans = max(ans, curr);
        // leave the house
        curr = curr - houses[idx];
        if (idx <= houses.size() - 1)
            stuffFinder(houses, ans, curr, idx + 1);
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return stuffFinderFast(nums, 0, dp);
    }
};
int main()
{
    return 0;
}