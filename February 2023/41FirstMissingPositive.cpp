#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int counter = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0 && nums[i] >= counter)
        {
            if (nums[i] == counter || nums[i] < counter)
                counter++;
        }
    }
    return counter;
    /*
    1 2 0
    for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    */
}
int main()
{
    // Given an unsorted integer array nums, return the smallest missing positive integer.

    // You must implement an algorithm that runs in O(n) time and uses constant extra space.
    vector<int> nums = {1, 1};
    cout << firstMissingPositive(nums) << endl;
    vector<int> nums2 = {1, 2, 0};
    cout << firstMissingPositive(nums2) << endl;
    vector<int> nums3 = {2, 1};
    cout << firstMissingPositive(nums3);
    return 0;
}