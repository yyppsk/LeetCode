#include "./bits/bits-stdc++.h"
using namespace std;
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            if ((nums[start] < 0) && abs(nums[start]) == nums[end])
            {
                return nums[end];
            }
            else if (abs(nums[start]) > nums[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}