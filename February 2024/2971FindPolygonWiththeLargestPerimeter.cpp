#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

long long largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.size() - 1;
    long long maxSum = -1;
    while (high > 0)
    {
        long long currentWindowSum = 0;

        for (int k = high - 1; k >= 0; k--)
        {
            currentWindowSum += nums[k];
        }
        if (currentWindowSum > nums[high])
        {
            maxSum = max(maxSum, currentWindowSum) + nums[high];
            break;
        }
        high--;
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {1, 12, 1, 2, 5, 50, 3};
    cout << "\n"
         << largestPerimeter(nums);
    return 0;
}