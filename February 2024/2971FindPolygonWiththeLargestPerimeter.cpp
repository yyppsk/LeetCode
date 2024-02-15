#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

class Solution2
{
public:
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
};

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long perimeter = 0, remaining = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < remaining)
            {
                perimeter = nums[i] + remaining;
            }
            remaining += nums[i];
        }
        return perimeter == 0 ? -1 : perimeter;
    }
};

int main()
{

    return 0;
}