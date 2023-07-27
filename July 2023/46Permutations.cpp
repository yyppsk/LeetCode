#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void recurStuff(vector<vector<int>> &ans, vector<int> &ds, int frequency[], vector<int> &nums)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!frequency[i])
        {
            ds.push_back(nums[i]);
            nums[i] = 1;
            recurStuff(ans, ds, frequency, nums);
            nums[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    /* solution 1
     vector<vector<int>> solution;
        int index = 0;
        helper(solution,index,nums);
        return solution;
    }
    */
    vector<int> ds;
    vector<vector<int>> ans;
    int frequency[nums.size()] = {0};
    recurStuff(ans, ds, frequency, nums);
    return ans;
};
int main()
{
    return 0;
}