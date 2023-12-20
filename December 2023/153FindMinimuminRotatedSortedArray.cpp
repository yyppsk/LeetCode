#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    // method 2
    int findMinRotated(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int mini = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // search space optimization,

            if (arr[low] <= arr[high])
            {
                mini = min(mini, arr[low]);
                break;
            }
            // left
            if (arr[low] <= arr[mid])
            {
                mini = min(mini, arr[low]);
                low = mid + 1;
            }
            else
            {
                mini = min(mini, arr[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
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
            if (arr[mid] > arr[0])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
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
        // method 2
        return findMinRotated(nums);
        // method 1
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int end = nums.size();
        int pivot = findpivot(nums, 0, end);
        return nums[pivot];
    }
};
int main()
{
    return 0;
}