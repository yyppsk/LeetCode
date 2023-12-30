#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        int pairs = 0;
        while (low < high)
        {
            if ((nums[low] + nums[high]) < target)
            {
                pairs += (high - low);
                low++;
            }
            else if ((nums[low] + nums[high]) >= target)
            {
                high--;
            }
        }
        return pairs;
    }
};
int main()
{
    return 0;
}