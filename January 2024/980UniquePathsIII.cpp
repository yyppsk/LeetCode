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
    int m, n;
    int finalResult = 0;
    int clearPath;
    vector<pair<int, int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void backtracking(vector<vector<int>> &grid, int count, int i, int j)
    {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
        {
            return;
        }
        if (grid[i][j] == 2)
        {
            if (count == clearPath)
                finalResult++;
            return;
        }

        grid[i][j] = -1;

        for (pair<int, int> &p : delta)
        {
            int newi = p.first + i;
            int newj = p.second + j;

            backtracking(grid, count + 1, newi, newj);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        int startX = 0, startY = 0;
        clearPath = 1; // self starting point
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] == 0)
                {
                    clearPath += 1;
                }
            }
        }
        int count = 0;
        backtracking(grid, count, startX, startY);
        return finalResult;
    }
};
int main()
{
    return 0;
}