#include <iostream>
#include <vector>
using namespace std;
int findUnsortedSubarray(vector<int> &nums)
{
    int size = nums.size();
    int left = 0, right = size - 1, maxNumberIndex = 0, minNumberIndex = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > nums[maxNumberIndex])
        {
            maxNumberIndex = i;
        }
        else if (nums[maxNumberIndex] > nums[i])
        {
            left = i;
        }
        if (nums[size - i - 1] < nums[minNumberIndex])
        {
            minNumberIndex = size - i - 1;
        }
        else if (nums[size - i - 1] > nums[minNumberIndex])
        {
            right = size - i - 1;
        }
    }
    if (right >= left)
    {
        return 0;
    }
    return left - right + 1;
}
// Time complexity : O(n)O(n). Four O(n)O(n) loops are used.

// Space complexity : O(1)O(1). Constant space is used.
int main()
{
    vector<int> num = {2, 6, 4, 8, 10, 9, 15, 0, 1};
    cout << findUnsortedSubarray(num);
    return 0;
}