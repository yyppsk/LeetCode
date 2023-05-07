#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
{
    /*Brute force idea
    vector<int> ans;
    set<vector<int>> res;
    for (int i = 0; i < obstacles.size(); i++)
    {
        vector<int> ans;
        ans.push_back(obstacles[0]);
        int start = 1;
        while (start <= i)
        {
            if (obstacles[i] >= obstacles[start])
            {
                ans.push_back(obstacles[start]);
            }
            start++;
        }
        res.insert(ans);
        ans.clear();
    }
    for (auto &vec : res)
    {
        for (auto &element : vec)
        {
            cout << element << " ";
        }
        ans.push_back(vec.size());
        cout << endl;
    }
    for (auto &element : ans)
    {
        cout << element << " ";
    }
    return {};
    */

    // List + BS
    int n = obstacles.size();
    vector<int> ans(n, 1), lis;

    for (int i = 0; i < n; i++)
    {
        int idxToInsert = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
        if (idxToInsert == lis.size())
        {
            lis.push_back(obstacles[i]);
        }
        else
        {
            lis[idxToInsert] = obstacles[i];
        }
        ans[i] = idxToInsert + 1;
    }
    return ans;
}
int main()
{
    vector<int> obstacles = {1, 2, 3, 2};
    longestObstacleCourseAtEachPosition(obstacles);
    return 0;
}