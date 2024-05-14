#include <bits/bits-stdc++.h>
using namespace std;
vector<pair<int, int>> delta = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int dfs(vector<vector<int>> &grid, int x, int y)
{

    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
        return 0;
    int gold = grid[x][y];
    grid[x][y] = 0;

    int maxGold = 0;
    for (auto &ele : delta)
    {
        int neighbourX = ele.first + x;
        int neighbourY = ele.second + y;
        maxGold = max(maxGold, dfs(grid, neighbourX, neighbourY));
    }
    grid[x][y] = gold;

    return gold + maxGold;
}
int getMaximumGold(vector<vector<int>> &grid)
{
    int maxGold = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] != 0)
                maxGold = max(maxGold, dfs(grid, i, j));
        }
    }
    return maxGold;
}
int main()
{
    vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << getMaximumGold(grid);
    return 0;
}