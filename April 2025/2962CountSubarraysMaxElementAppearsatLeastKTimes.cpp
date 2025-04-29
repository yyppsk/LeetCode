#include <bits/bits-stdc++.h>
using namespace std;
long long countSubarrays(vector<int> &nums, int k)
{
    int maxi = *max_element(nums.begin(), nums.end());
    int start = 0, count = 0;
    long long result = 0;

    for (int end = 0; end < nums.size(); end++)
    {
        if (nums[end] == maxi)
        {
            count++;
        }

        while (count >= k)
        {
            if (nums[start] == maxi)
            {
                count--;
            }
            start++;
        }

        result += start;
    }

    return result;
}
int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    countSubarrays(nums, k);
    return 0;
}