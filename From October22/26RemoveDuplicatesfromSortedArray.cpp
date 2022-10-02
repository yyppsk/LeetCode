#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map >
using namespace std;
int removeDuplicatessolution1(vector<int> &nums)
{
    int index = 0;
    int done;
    for (auto i : nums)
    {
        auto lower = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
        nums[index] = nums[lower];
        if (index == 0)
        {
            done = nums[lower];
            ++index;
        }
        if (done != nums[lower])
        {
            ++index;
            done = nums[lower];
        }
    }
    return index;
}
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicatessolution1(nums);
    return 0;
}