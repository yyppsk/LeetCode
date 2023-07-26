#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findStuff(vector<int> &nums, vector<vector<int>> &ans, vector<int> &dataStr, int idx)
{
    ans.push_back(dataStr);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        dataStr.push_back(nums[i]);
        findStuff(nums, ans, dataStr, i + 1);
        dataStr.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> dataStr;
    sort(nums.begin(), nums.end()); // to ensure duplicates remain together
    findStuff(nums, ans, dataStr, 0);
    return ans;
}
int main()
{
    return 0;
}