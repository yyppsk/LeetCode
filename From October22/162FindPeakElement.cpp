#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    if (nums.size() == 2)
    {
        if (nums[0] > nums[1])
            return 0;
        else
            return 1;
    }
    if (nums[0] > nums[1])
        return 0;
    if (nums[nums.size() - 1] > nums[nums.size() - 2])
        return nums.size() - 1;
    int start = 1;
    int end = nums.size() - 2;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid; // if mid == peak ( case 2 )
        else if (nums[mid] < nums[mid - 1])
            end = mid - 1; // downward slope and search space left side ( case 1)
        else if (nums[mid] < nums[mid + 1])
            start = mid + 1; // upward slope and search space right side ( case 3 )
    }
    return 0;
}
int main()
{
    vector<int> arr = {2, 1};
    cout << findPeakElement(arr);
    return 0;
}