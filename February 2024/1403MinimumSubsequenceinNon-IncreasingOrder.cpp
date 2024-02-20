#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        vector<int> result;
        int localsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            localsum += nums[i];
            sum -= nums[i];
            if (localsum > sum)
            {
                result.push_back(nums[i]);
                break;
            }
            else
            {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}