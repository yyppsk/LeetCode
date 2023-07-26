#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findSum(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &dataStructure, int idx)
{
    // base case
    if (target == 0)
    {
        ans.push_back(dataStructure);
        return;
    }
    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue; // dont have to include the stuff which have been included already in the previous call for same element
        if (candidates[i] > target)
            break;
        dataStructure.push_back(candidates[i]);
        findSum(candidates, target - candidates[i], ans, dataStructure, i + 1);
        dataStructure.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> dataStructure;
    vector<vector<int>> ans;
    findSum(candidates, target, ans, dataStructure, 0);
    return ans;
}
int main()
{
    return 0;
}