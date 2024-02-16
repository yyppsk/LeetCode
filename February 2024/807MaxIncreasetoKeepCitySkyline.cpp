#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        n = grid.size();
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int rowMax = findrowMax(grid, i);
                int colMax = findcolMax(grid, j);
                answer += abs(grid[i][j] - min(rowMax, colMax));
                grid[i][j] = min(rowMax, colMax);
            }
        }
        return answer;
    }

private:
    int findrowMax(vector<vector<int>> &grid, int currRow)
    {
        int maxi = INT_MIN;
        for (int col = 0; col < n; col++)
        {
            maxi = max(grid[currRow][col], maxi);
        }
        return maxi;
    }
    int findcolMax(vector<vector<int>> &grid, int currCol)
    {
        int maxi = INT_MIN;
        for (int row = 0; row < n; row++)
        {
            maxi = max(grid[row][currCol], maxi);
        }
        return maxi;
    }
};

// Approach 2
class Solution
{
public:
    int n;
    int cacheRow[51];
    int cacheCol[51];
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        n = grid.size();
        memset(cacheRow, INT_MIN, sizeof(cacheRow));
        memset(cacheCol, INT_MIN, sizeof(cacheCol));
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int rowMax = findrowMax(grid, i, j);
                int colMax = findcolMax(grid, j, i);
                answer += abs(grid[i][j] - min(rowMax, colMax));
                grid[i][j] = min(rowMax, colMax);
            }
        }
        return answer;
    }

private:
    int findrowMax(vector<vector<int>> &grid, int currRow, int currCol)
    {
        int maxi = INT_MIN;
        if (cacheRow[currRow] != INT_MIN)
        {
            if (cacheRow[currRow] > grid[currRow][currCol])
                return cacheRow[currRow];
            else
            {
                cacheRow[currRow] = grid[currRow][currCol];
                return cacheRow[currRow];
            }
        }
        if (cacheRow[currRow] == INT_MIN)
        {
            for (int col = 0; col < n; col++)
            {
                maxi = max(grid[currRow][col], maxi);
            }
        }
        return cacheRow[currRow] = maxi;
    }
    int findcolMax(vector<vector<int>> &grid, int currCol, int currRow)
    {
        if (cacheCol[currCol] != INT_MIN)
        {
            if (cacheCol[currCol] > grid[currRow][currCol])
                return cacheCol[currCol];
            else
            {
                cacheCol[currCol] = grid[currRow][currCol];
                return cacheCol[currCol];
            }
        }
        int maxi = INT_MIN;
        if (cacheCol[currCol] == INT_MIN)
        {
            for (int row = 0; row < n; row++)
            {
                maxi = max(grid[row][currCol], maxi);
            }
        }
        return cacheCol[currCol] = maxi;
    }
};
int main()
{
    return 0;
}