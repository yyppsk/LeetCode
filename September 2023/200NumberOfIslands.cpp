#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        // when a node comes, mark it as visited
        vector<pair<int, int>> delta = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size(), m = grid[0].size();

        while (!q.empty())
        {
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();
            for (int i = 0; i < delta.size(); i++)
            {
                int neighbourRow = currentRow + delta[i].first;
                ;
                int neighbourCol = currentCol + delta[i].second;
                if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && grid[neighbourRow][neighbourCol] == '1' && !visited[neighbourRow][neighbourCol])
                {
                    visited[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow, neighbourCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}