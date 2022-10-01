#include <iostream>
using namespace std;
int main() int largestPerimeter(vector &nums)
{
    // to find the largest perimeter in sorted array
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 2; i--)
    {
        // properties of triangle to exist
        if ((nums[i - 2] + nums[i - 1] > nums[i]) && (nums[i - 1] - nums[i - 2] < nums[i]) && (nums[i] - nums[i - 1] < nums[i - 2]) && (nums[i] - nums[i - 2] < nums[i - 1]))
        {
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    return 0;
}
{
    return 0;
}