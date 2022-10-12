#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findpeak(vector<int> &nums)
{
    int start = 0, end = nums.size();
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        // kya mid start wale se bada hai?
        if (nums[mid] > nums[0])
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}
bool search(vector<int> &nums, int target)
{
    int peak = findpeak(nums);
}
int main()
{
    vector<int> nums = {3, 4, 5, 6, 7, 8, 1, 2};
    int target = 0;
    cout << findpeak(nums);
    // cout << search(nums, target);
    return 0;
}