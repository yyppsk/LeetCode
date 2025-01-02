#include <bits/bits-stdc++.h>
using namespace std;
bool canBeIncreasing(vector<int> &nums)
{
    int chance = 0;
    for (int i = 1; i < nums.size() && chance < 2; ++i)
    {
        if (nums[i - 1] >= nums[i])
        {
            ++chance;
            if (i > 1 && nums[i - 2] >= nums[i])
                nums[i] = nums[i - 1];
        }
    }
    return chance < 2;
}

// 1,2,10,5,7
// 2,3,1,2
int main()
{
    return 0;
}