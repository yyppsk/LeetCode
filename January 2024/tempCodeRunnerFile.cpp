vector<pair<int, int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int counter = 0;

void solve(int m, int n, vector<vector<int>> &mat, int maxMove, int startRow, int startColumn)
{
    if (maxMove < 0)
    {
        return; // No need to continue if maxMove is negative
    }

    // Mark the current cell as visited
    mat[startRow][startColumn] = -1;

    for (auto &dir : delta)
    {
        int row = dir.first + startRow;
        int col = dir.second + startColumn;

        if (row < m && row >= 0 && col < n && col >= 0 && mat[row][col] != -1)
        {
            solve(m, n, mat, maxMove - 1, row, col);
        }
        else if ((row >= m || row < 0 || col >= n || col < 0) && maxMove != 0)
        {
            counter++;
        }
    }

    // Reset the current cell to its original state
    mat[startRow][startColumn] = 0;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<int>> mat(m, vector<int>(n, 0));
    solve(m, n, mat, maxMove, startRow, startColumn);
    return counter % 1000000007;
}