#include <bits/bits-stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> delta{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;
    void DFS(vector<vector<int>> &grid, int i, int j,
             vector<vector<bool>> &visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
            grid[i][j] == 0)
            return;

        visited[i][j] = 1;

        for (auto &move : delta)
        {
            int currI = i + move[0];
            int currJ = j + move[1];
            DFS(grid, currI, currJ, visited);
        }
    }

    int numberOfIslandsDFS(vector<vector<int>> &grid)
    {

        vector<vector<bool>> visited(m, vector<bool>(n));
        int islands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    DFS(grid, i, j, visited);
                    islands += 1;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int islands = numberOfIslandsDFS(grid);
        if (islands > 1 or islands == 0)
        {
            return 0;
        }
        else
        {

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        grid[i][j] = 0;

                        islands = numberOfIslandsDFS(grid);

                        grid[i][j] = 1;
                        if (islands > 1 or islands == 0)
                            return 1;
                    }
                }
            }
        }

        return 2;
    }
};

int minDays(vector<vector<int>> &grid)
{
}
int main()
{
    return 0;
}