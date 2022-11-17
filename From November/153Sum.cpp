#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
    }
    return ans;
}
int main()
{
    // i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}