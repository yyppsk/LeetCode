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
int removeDuplicatessolution2(vector<int> &nums)
{
    int start = 0;
    int end = 1;
    int index = 0;
    while (start <= end && end < nums.size())
    {
        if (nums[start] == nums[end])
        {
            end += 1;
        }
        else
        {
            nums[index] = nums[start];
            start = end;
            index += 1;
        }
    }
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return index + 1;
}
int removesol3(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removesol3(nums);
    return 0;
}