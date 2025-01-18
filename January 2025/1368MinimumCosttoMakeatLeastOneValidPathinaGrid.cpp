#include <bits/bits-stdc++.h>
using namespace std;

vector<vector<int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
int findCost(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> vis, int cost)
{
    if (i == n - 1 && j == m - 1)
    {
        return cost;
    }

    vis[i][j] = true; // Mark current cell as visited
    int minCost = INT_MAX;

    for (int dir = 0; dir <= 3; dir++)
    {
        int move_i = i + delta[dir][0];
        int move_j = j + delta[dir][1];

        // Valid move
        if (move_i >= 0 && move_j >= 0 && move_i < n && move_j < m && !vis[move_i][move_j])
        {
            // cout << "From " << i << "," << j << " to : ";
            // cout << "Visit " << move_i << "," << move_j << "\n";
            int nextCost = cost;
            if (grid[i][j] != dir + 1)
            {
                nextCost += 1;
            }

            minCost = min(minCost, findCost(move_i, move_j, grid, vis, nextCost));
        }
    }

    vis[i][j] = false;
    return minCost;
}

int minCost(vector<vector<int>> &grid)
{
    n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    return findCost(0, 0, grid, vis, 0);
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    cout << minCost(grid);
    return 0;
}