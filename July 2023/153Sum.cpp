#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSumBrute(vector<int> &nums)
    {
        // TC 310 / 312
        set<vector<int>> answer;
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> hashset;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int third = -(nums[i] + nums[j]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> t = {nums[i], nums[j], third};
                    sort(t.begin(), t.end());
                    answer.insert(t);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> result(answer.begin(), answer.end());
        return result;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Because that will give repeated sequences
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    // increase the sum
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    // got it
                    vector<int> t = {nums[i], nums[j], nums[k]};
                    ans.push_back(t);
                    j++, k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}