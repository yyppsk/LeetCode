#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> result;
        result.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > result.back())
            {
                result.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
                result[index] = nums[i];
            }
        }
        return result.size();
    }
};
int main()
{
    return 0;
}