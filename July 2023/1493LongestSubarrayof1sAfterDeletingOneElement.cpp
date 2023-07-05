#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Solution 3
int longestSubarray(vector<int> &nums)
{
    // Keeps
    int lastSeenZero = -1, result = 0, i = 0, j = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0)
        {
            i = lastSeenZero + 1;
            lastSeenZero = j;
        }
        result = max(result, j - i);
        j++;
    }

    return result;
}
// Solution 2
int longestSubarray2(vector<int> &nums)
{
    int zero = 0, result = INT_MIN, i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 0)
            zero++;
        while (zero > 1)
        {
            if (nums[i] == 0)
                zero--;
            i++;
        }
        result = max(result, j - i);
    }
    return result;
}
int n;
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