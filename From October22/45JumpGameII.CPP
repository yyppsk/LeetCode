#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (auto i : dp)
    {
        cout << i << endl;
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        int minjump = INT_MAX - 1;
        for (int j = i + 1; min(n, nums[i] + i); j++)
        {
            // nums[i] tells wah[a se kitna jump kr skte hain
            minjump = min(minjump, dp[j]);
        }
        dp[i] = 1 + minjump;
    }

    return dp[0];
}
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}