#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int spaceOptimized(vector<int> &stones, vector<int> &dp)
{
    // space optimization
    int previous = 0, secondPrev = 0;
    for (int i = 1; i < stones.size(); i++)
    { // previous = dp[i-1]
        int left = previous + abs(stones[i] - stones[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = secondPrev + abs(stones[i] - stones[i - 2]);
        // return typically
        int curr = min(left, right);
        secondPrev = previous;
        previous = curr;
    }
    return previous;
}
int dpsoln(vector<int> &stones, vector<int> &dp)
{
    // tabulation
    dp[0] = 0; // base case was to return the 0 when idx is 0
    for (int i = 1; i < stones.size(); i++)
    {
        int left = dp[i - 1] + abs(stones[i] - stones[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(stones[i] - stones[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[stones.size() - 1];
}
int jumpsOptimized(int idx, vector<int> &stones, vector<int> &dp)
{
    // memoization
    if (idx == 0)
        return 0; // cost of 0->0 is 0
    if (dp[idx] != -1)
        return dp[idx];
    int left = jumpsOptimized(idx - 1, stones, dp) + abs(stones[idx] - stones[idx - 1]);
    int right = INT_MAX;
    if (idx > 1)
        right = jumpsOptimized(idx - 2, stones, dp) + abs(stones[idx] - stones[idx - 2]);

    return dp[idx] = min(left, right);
}
int jumps1(int idx, vector<int> &stones)
{
    if (idx == 0)
        return 0; // cost of 0->0 is 0
    int left = jumps1(idx - 1, stones) + abs(stones[idx] - stones[idx - 1]);
    int right = INT_MAX;
    if (idx > 1)
        right = jumps1(idx - 2, stones) + abs(stones[idx] - stones[idx - 2]);

    return min(left, right);
}
int maxJump(vector<int> &stones)
{
    vector<int> dp(stones.size() + 1, -1);
    return jumpsOptimized(stones.size() - 1, stones, dp);
}
int main()
{
    return 0;
}