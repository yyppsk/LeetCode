#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        for (auto &row : grid)
        {
            sort(row.begin(), row.end());
        }
        int ans = 0;
        for (int col = 0; col < grid[0].size(); col++)
        {
            int maxRow = 0;
            for (int row = 0; row < grid.size(); row++)
            {
                maxRow = max(maxRow, grid[row][col]);
            }
            ans += maxRow;
        }
        return ans;
    }
};
int main()
{
    return 0;
}