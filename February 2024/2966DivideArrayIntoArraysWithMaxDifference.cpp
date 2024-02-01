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
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 2; i <= nums.size(); i += 3)
        {
            if (nums[i] - nums[i - 2] > k)
                return {};
            res.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }
        return res;
    }
};
int main()
{
    return 0;
}