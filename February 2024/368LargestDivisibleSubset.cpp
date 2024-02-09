#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubsetDP(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> previousIndex(nums.size(), -1);

        int lastindex = 0;
        int maxl = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        previousIndex[i] = j;
                    }

                    if (dp[i] > maxl)
                    {
                        maxl = dp[i];
                        lastindex = i;
                    }
                }
            }
        }
        vector<int> result;
        while (lastindex != -1)
        {
            result.push_back(nums[lastindex]);
            lastindex = previousIndex[lastindex];
        }
        return result;
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> temp;
        int prev = -1;
        solve(0, nums, result, temp, prev);
        return result;
    }

private:
    void solve(int idx, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev)
    {
        if (idx >= nums.size())
        {
            if (temp.size() > result.size())
            {
                result = temp;
            }
            return;
        }

        // take the element only when
        if (prev == -1 || nums[idx] % prev == 0)
        {
            temp.push_back(nums[idx]); // take because reference
            solve(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }

        solve(idx + 1, nums, result, temp, prev);
    }
};
int main()
{
    return 0;
}