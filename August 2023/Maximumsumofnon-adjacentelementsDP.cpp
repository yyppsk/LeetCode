#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include <bits/stdc++.h>
int findstuffSpaceOptimized(vector<int> &nums)
{
    int prev = nums[0];
    int prev2 = 0;
    // if(idx < 0)
    //     return 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int Notpick = 0 + prev;
        int curr = max(pick, Notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int findstuffDP(vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];
    ;
    // if(idx < 0)
    //     return 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int Notpick = 0 + dp[i - 1];
        dp[i] = max(pick, Notpick);
    }
    return dp[nums.size() - 1];
}
int findstuffMem(int idx, vector<int> &nums, vector<int> &dp)
{
    if (idx == 0)
        return nums[idx];
    if (idx < 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    // pick and not pick
    int pick = nums[idx] + findstuffMem(idx - 2, nums, dp);
    int notPick = 0 + findstuffMem(idx - 1, nums, dp);

    return dp[idx] = max(pick, notPick);
}
int findstuffRec(int idx, vector<int> &nums)
{
    if (idx == 0)
        return nums[idx];
    if (idx < 0)
        return 0;
    // pick and not pick
    int pick = nums[idx] + findstuffRec(idx - 2, nums);
    int notPick = 0 + findstuffRec(idx - 1, nums);

    return max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size(), -1);
    return findstuffSpaceOptimized(nums);
}
int main()
{
    return 0;
}