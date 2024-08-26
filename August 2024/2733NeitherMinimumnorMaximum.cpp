#include <bits/bits-stdc++.h>
using namespace std;
int findNonMinOrMax(vector<int> &nums)
{
    int min_ele = INT_MAX;
    int max_ele = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max_ele)
        {
            max_ele = nums[i];
        }

        if (nums[i] < min_ele)
        {
            min_ele = nums[i];
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != max_ele && nums[i] != min_ele)
        {
            return nums[i];
        }
    }

    return -1;
}
int main()
{
    return 0;
}