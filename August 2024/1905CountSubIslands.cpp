#include <bits/bits-stdc++.h>
using namespace std;

bool checkCommonIsland(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
{
    if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size())
    {
        return true;
    }

    if (grid2[i][j] != 1)
    {
        return true;
    }

    grid2[i][j] = -1;

    bool res = (grid1[i][j] == 1);

    res = res & checkCommonIsland(grid1, grid2, i + 1, j);
    res = res & checkCommonIsland(grid1, grid2, i - 1, j);
    res = res & checkCommonIsland(grid1, grid2, i, j + 1);
    res = res & checkCommonIsland(grid1, grid2, i, j - 1);

    return res;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int subIsland = 0;
    int n = grid2.size(), m = grid2[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid2[i][j] == 1 && checkCommonIsland(grid1, grid2, i, j))
            {
                subIsland += 1;
            }
        }
    }

    return subIsland;
}
int main()
{
    return 0;
}