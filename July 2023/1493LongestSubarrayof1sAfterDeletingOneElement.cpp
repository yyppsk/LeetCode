#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
// Solution 2
//  Solution 1
/*
int findMax(vector<int> &nums, int skip)
{
    int result = 0, counter = 0;
    n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i == skip)
        {
            continue;
        }

        if (nums[i] == 1)
        {

            counter++;
            result = max(result, counter);
        }
        else
        {
            counter = 0;
        }
    }
    return result;
}

int longestSubarray(vector<int> &nums)
{
    n = nums.size();
    // for looping for i
    // skipping the index where 0 occurs
    int zeroes = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            zeroes++;
            result = max(result, findMax(nums, i));
        }
    }
    if (zeroes == 0)
        return n - 1;
    return result;
}
*/
int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << longestSubarray(nums);
    return 0;
}