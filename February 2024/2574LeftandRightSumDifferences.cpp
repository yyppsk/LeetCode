#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return {0};
        }

        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++)
        {
            left[i] += nums[i - 1] + left[i - 1];
        }
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            right[i - 1] += nums[i] + right[i];
        }

        for (int i = 0; i < left.size(); i++)
        {
            left[i] = abs(left[i] - right[i]);
        }
        return left;
    }
};
int main()
{
    return 0;
}