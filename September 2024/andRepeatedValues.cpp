#include <bits/bits-stdc++.h>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
        {
            freq[grid[i][j]]++;
        }
    }
    int repeat = 0, miss = 0, n = grid.size() * grid.size();
    for (int i = 1; i <= n; ++i)
    {
        if (freq[i] == 2)
            repeat = i;
        if (freq[i] == 0)
            miss = i;
    }
    return {repeat, miss};
}
int main()
{
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    findMissingAndRepeatedValues(grid);
    return 0;
}
// 1+2+3+4