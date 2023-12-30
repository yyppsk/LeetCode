#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int minCost2(string colors, vector<int> &neededTime)
    {
        int ans = 0, maxCost = 0, sumcost = 0, n = colors.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && colors[i] != colors[i - 1])
            {
                ans += sumcost - maxCost;
                sumcost = 0;
                maxCost = 0;
            }
            sumcost += neededTime[i];
            maxCost = max(maxCost, neededTime[i]);
        }
        ans += sumcost - maxCost;
        return ans;
    }
    int minCost(string colors, vector<int> &neededTime)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = colors.size();
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                res += min(neededTime[i - 1], neededTime[i]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}