#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    int findmax = INT_MIN, findmin = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
        if (findmax < nums[i])
            findmax = nums[i];
    for (int i = 0; i < nums.size(); i++)
        if (findmin > nums[i] && nums[i] != 0)
            findmin = nums[i];
    cout << findmin << " " << findmax << endl;
    if (findmin < 0 && findmax < 0)
        return 1;
    int j = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (j >= findmin && findmin >= nums[i] && nums[i] != 0)
            j++;
    }
    return j;
}
int main()
{
    // Given an unsorted integer array nums, return the smallest missing positive integer.

    // You must implement an algorithm that runs in O(n) time and uses constant extra space.
    vector<int> nums = {1, 2, 0};
    cout << firstMissingPositive(nums);
    return 0;
}