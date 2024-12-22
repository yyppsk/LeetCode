#include <bits/bits-stdc++.h>
using namespace std;

/*
TC : [5,3,8,2,6,1,4,6]
[[0,7],[3,5],[5,2],[3,0],[1,6]]
Expected
[7,6,-1,4,6]

*/
// TLE 946
vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
{
    vector<int> res;

    for (auto &query : queries)
    {
        int alice = query[0], bob = query[1];

        if (alice == bob)
        {
            res.push_back(alice);
            continue;
        }

        int aliceHeight = heights[alice], bobHeight = heights[bob];

        // Move alice direct to bob
        if (alice < bob && aliceHeight < bobHeight)
        {
            res.push_back(bob);
            continue;
        }

        // Move bob to alice
        if (bob < alice && bobHeight < aliceHeight)
        {
            res.push_back(alice);
            continue;
        }

        // leftmost valid
        int start = max(alice, bob) + 1;
        int target = -1;

        for (int i = start; i < heights.size(); i++)
        {
            if (heights[i] > aliceHeight && heights[i] > bobHeight)
            {
                target = i;
                break;
            }
        }

        res.push_back(target);
    }

    return res;
}
int main()
{
    return 0;
}