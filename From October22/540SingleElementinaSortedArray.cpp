#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int start = 1, end = nums.size() - 2;
    while (start <= end)
    {
        int mid = start + (end + start) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return mid;
        if (nums[nums[mid] != nums[mid + 1]])
            end = mid - 1;
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(arr);
    return 0;
}