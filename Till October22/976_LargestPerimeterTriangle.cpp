/*
    Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int largestPerimeter(vector<int> &nums)
{
    // make sure a+c>b
    // a+b>c
    // b+c>a
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (auto element : nums)
    {
        cout << element << " ";
    }
    cout << endl;
    for (int i = 2; i < nums.size(); i++)
    {
        printf("When i = %d then : \n", i);
        printf("nums[i - 2](%d) < nums[i - 1](%d) + nums[i](%d)\n", nums[i - 2], nums[i - 1], nums[i]);
        if (nums[i - 2] < nums[i - 1] + nums[i])
            return nums[i - 2] + nums[i - 1] + nums[i];
    }

    return 0;
}
int main()
{
    vector<int> nums = {3, 2, 3, 4, 1, 6};
    cout << largestPerimeter(nums);
    return 0;
}
/*
int largestPerimeter(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 2; i < nums.size(); i++){
            if( nums[i-2] < nums[i-1] + nums[i])
                return nums[i - 2] + nums[i - 1] + nums[i];
        }
        return 0;
    }
*/