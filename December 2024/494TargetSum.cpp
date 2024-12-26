#include <bits/bits-stdc++.h>
using namespace std;
int res = 0;
void combination(int curr, int idx, vector<int> &nums, int &target, int &ignore)
{

    if (idx == nums.size() - 1 && curr == target)
    {
        res += 1;
        return;
    }

    if (idx == nums.size() - 1)
    {
        return;
    }

    if (idx != ignore)
    {
        // neg

        combination(curr - nums[idx], idx + 1, nums, target, ignore);
        // pos

        combination(curr + nums[idx], idx + 1, nums, target, ignore);
    }
}

int findTargetSumWays(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        combination(-1 * nums[i], 0, nums, target, i);

        combination(nums[i], 0, nums, target, i);
    }
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    findTargetSumWays(nums, target);
    return 0;
}