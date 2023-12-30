#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int mod = 1000000000 + 7;
    int fn(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (target < n || n * k < target)
        {
            return 0;
        }
        if (dp[n][target] != 0)
        {
            return dp[n][target];
        }
        // if(currsum > target)
        //     return 0;
        int ans = 0;
        for (int diceFace = 1; diceFace <= k; diceFace++)
        {
            if (target < diceFace)
                break;
            // ans += fn(n-1,i,k,target,currsum + i, ans);
            ans = (ans + fn(n - 1, k, target - diceFace, dp) % mod) % mod;
        }
        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        if (n == 0 && target == 0)
            return 1;
        if (target < n || n * k < target)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        return fn(n, k, target, dp);
    }
};
int main()
{
    return 0;
}