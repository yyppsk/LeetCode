#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findpeak(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        // kya mid start wale se bada hai?
        if (nums[mid] >= nums[0])
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}
int binarysearch(vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "arrmid : " << arr[mid] << endl;
        if (arr[mid] == target)
            return true;
        if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}
bool search(vector<int> &nums, int target)
{
    int peak = findpeak(nums);
    if (nums.size() > 3)
        if (nums[peak + 1]<nums[peak]> nums[peak + 1] && nums[peak] == target)
            return true;
    cout << "peak : " << peak << endl;
    int end = nums.size();
    int size = nums.size();

    if ((target >= nums[peak]) && (target <= nums[size - 1]))
        return binarysearch(nums, peak, size - 1, target);
    return binarysearch(nums, 0, peak - 1, target);
}
int main()
{
    vector<int> nums = {2, 2, 2, 3, 2, 2, 2};
    int target = 3;
    cout << search(nums, target);
    return 0;
}