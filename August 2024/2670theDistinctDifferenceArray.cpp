#include <bits/bits-stdc++.h>
using namespace std;
vector<int> distinctDifferenceArray_1(vector<int> &nums)
{
    vector<int> result;

    for (int k = 0; k < nums.size(); k++)
    {
        unordered_set<int> leftUnique;
        for (int i = 0; i <= k; i++)
        {
            leftUnique.insert(nums[i]);
        }
        unordered_set<int> rightUnique;
        for (int i = k + 1; i < nums.size(); i++)
        {
            rightUnique.insert(nums[i]);
        }
        result.push_back(leftUnique.size() - rightUnique.size());
    }

    return result;
}

vector<int> distinctDifferenceArray(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> prefix, suffix;
    for (auto n : nums)
    {
        suffix[n]++;
    }
    for (auto n : nums)
    {
        prefix[n]++;
        suffix[n]--;
        if (suffix[n] == 0)
            suffix.erase(n);
        ans.push_back(prefix.size() - suffix.size());
    }
    return ans;
}

int main()
{
    return 0;
}