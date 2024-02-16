#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        unordered_set<int> vis;
        for (int i = 0; i < ranges.size(); i++)
        {
            int r1 = ranges[i][0];
            int r2 = ranges[i][1];
            while (r1 <= r2)
            {
                vis.insert(r1);
                r1++;
            }
        }
        cout << vis.size();
        for (int i = left; i <= right; i++)
        {
            if (vis.find(i) == vis.end())
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}