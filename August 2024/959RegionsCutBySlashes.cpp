#include <bits/bits-stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &space, int i, int j)
{
    if (min(i, j) < 0 || max(i, j) > space.size() || space[i][j] != 0)
    {
        return 0;
    }

    space[i][j] = 1;

    return 1 + dfs(space, i - 1, j) + dfs(space, i + 1, j) + dfs(space, i, j - 1) + dfs(space, i, j + 1);
}
int regionsBySlashes(vector<string> &grid)
{
    int n = grid.size();
    vector<vector<int>> space(n * 3, vector<int>(n * 3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '/')
            {
                space[i * 3][j * 3 + 2] = 1;
                space[i * 3 + 1][j * 3 + 1] = 1;
                space[i * 3 + 2][j * 3] = 1;
            }
            else if (grid[i][j] == '\\')
            {
                space[i * 3][j * 3] = 1;
                space[i * 3 + 1][j * 3 + 1] = 1;
                space[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n * 3; i++)
    {
        for (int j = 0; j < n * 3; j++)
        {
            answer += dfs(space, i, j) ? 1 : 0;
        }
    }

    return answer;
}
int main()
{
    return 0;
}