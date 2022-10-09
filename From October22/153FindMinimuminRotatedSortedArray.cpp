#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findpivot(vector<int> arr, int start, int end)
{
    end = end - 1;
    if (arr[end] > arr[0])
    {
        return 0;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        if (arr[mid] > arr[mid + 1])
            return mid + 1;
        if (arr[mid - 1] > arr[mid])
            return mid;
    }
    return start;
}
int findMin(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int end = nums.size();
    int pivot = findpivot(nums, 0, end);
    cout << pivot << endl;
    return pivot;
}
int main()
{ // 11, 13, 15, 17
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // 6 7 4 3 2 1
    findMin(nums);
    return 0;
}