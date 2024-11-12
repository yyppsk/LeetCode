#include <bits/bits-stdc++.h>
using namespace std;

// Extreme Brute Force
int maxSubArrayLen(vector<int> &nums, int k)
{
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            int length = 1;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
                length += 1;
                // cout << nums[k] << " ";
            }
            // cout << "\n";
            if (sum == k)
            {
                maxLen = max(maxLen, length);
            }
        }
        // cout << "\n";
    }

    cout << maxLen;
}
int main()
{
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;

    maxSubArrayLen(nums, k);
    return 0;
}