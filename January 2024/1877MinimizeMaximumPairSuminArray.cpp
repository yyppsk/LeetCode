#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        int maxi = INT_MIN;
        while (low < high)
        {
            maxi = max(maxi, nums[low++] + nums[high--]);
        }
        return maxi;
    }
};
int main()
{
    return 0;
}