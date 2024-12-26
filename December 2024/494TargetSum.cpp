#include <bits/bits-stdc++.h>
using namespace std;

// Brute Recursive
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

// Better Recursive
class Solution
{
public:
    int totalWays = 0;

    int findTargetSumWays(vector<int> &nums, int target)
    {
        combination(nums, 0, 0, target);
        return totalWays;
    }

private:
    void combination(vector<int> &nums, int currentIndex, int currentSum,
                     int target)
    {
        if (currentIndex == nums.size())
        {
            if (currentSum == target)
            {
                totalWays++;
            }
        }
        else
        {
            combination(nums, currentIndex + 1,
                        currentSum + nums[currentIndex], target);
            combination(nums, currentIndex + 1,
                        currentSum - nums[currentIndex], target);
        }
    }
};

// Memoization

class Solution_Memoization
{
public:
    vector<vector<int>> mem;

    int combination(int curr, int idx, vector<int> &nums, int target)
    {

        int offset = 1000;

        if (idx == nums.size())
            return (curr == target) ? 1 : 0;

        if (mem[idx][curr + offset] != -1)
            return mem[idx][curr + offset];

        int add = combination(curr + nums[idx], idx + 1, nums, target);
        int subtract = combination(curr - nums[idx], idx + 1, nums, target);

        mem[idx][curr + offset] = add + subtract;
        return mem[idx][curr + offset];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        mem.assign(nums.size(), vector<int>(2001, -1));
        return combination(0, 0, nums, target);
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    findTargetSumWays(nums, target);
    return 0;
}