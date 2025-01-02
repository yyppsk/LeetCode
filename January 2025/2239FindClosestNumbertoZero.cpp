#include <bits/bits-stdc++.h>
using namespace std;
int findClosestNumber(vector<int> &nums)
{
    int closestDistance = INT_MAX, closestNumber;
    for (int i = 0; i < nums.size(); i++)
    {
        if (abs(nums[i]) < closestDistance)
        {
            closestDistance = abs(nums[i]);
            closestNumber = nums[i];
        }
        else if (abs(nums[i]) == closestDistance &&
                 nums[i] > closestNumber)
        {
            closestNumber = nums[i];
        }
    }
    return closestNumber;
}
int main()
{
    return 0;
}