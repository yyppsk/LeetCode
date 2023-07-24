#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findStuff(vector<int> &candidates, int target, vector<int> ds, int idx, vector<vector<int>> &ans)
{
    if (idx == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    // take it
    if (candidates[idx] <= target)
    {
        ds.push_back(candidates[idx]);
        findStuff(candidates, target - candidates[idx], ds, idx, ans);
        ds.pop_back(); // pop tb kroge na jab pick kroge
    }

    findStuff(candidates, target, ds, idx + 1, ans);
    // leave it
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findStuff(candidates, target, ds, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); i++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    return 0;
}