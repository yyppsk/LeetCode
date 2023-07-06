#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int low = 0, high = 0, sum = 0;
    int window = INT_MAX;

    if (nums.size() == 1)
    {
        if (nums[0] == target)
            return 1;
        else
            return 0;
    }
    sum = nums[0];
    while (high < nums.size())
    {
        if (sum >= target)
        {
            window = min(window, high - low + 1);
            sum -= nums[low];
            ++low;
        }
        else
        {
            ++high;
            if (high < nums.size())
                sum += nums[high];
        }
    }
    if (window == INT_MAX)
        return 0;
    else
        return window;
}
int main()
{
    vector<int> num = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, num);
    return 0;
}