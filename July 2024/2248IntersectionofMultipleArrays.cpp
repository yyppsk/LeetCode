#include <bits/bits-stdc++.h>
using namespace std;

vector<int> intersection(vector<vector<int>> &nums)
{
    vector<int> result;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            mp[nums[i][j]]++;

            if (mp[nums[i][j]] >= nums.size())
            {
                result.push_back(nums[i][j]);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    vector<vector<int>> stuff = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};

    intersection(stuff);
    return 0;
}