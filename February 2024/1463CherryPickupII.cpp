#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class SolutionRecur
{
public:
    int mcol, nrow;
    int findmax(vector<vector<int>> &grid, int row, int col1, int col2)
    {

        if (row >= nrow)
        {
            return 0;
        }
        int cherry = grid[row][col1]; // r1
        if (col2 != col1)
        {
            cherry += grid[row][col2];
        }

        int maximum = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newRowCommon = row + 1;
                int newcolRobot1 = col1 + i;
                int newcolRobot2 = col2 + j;

                if (newcolRobot1 >= 0 && newcolRobot1 < mcol &&
                    newcolRobot2 >= 0 && newcolRobot2 < mcol)
                    maximum = max(maximum, findmax(grid, newRowCommon,
                                                   newcolRobot1, newcolRobot2));
            }
        }
        return cherry + maximum;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        nrow = grid.size(), mcol = grid[0].size();
        return findmax(grid, 0, 0, mcol - 1);
    }
};

// Memoization
class Solution
{
public:
    int mcol, nrow;
    int memo[71][71][71];
    int findmax(vector<vector<int>> &grid, int row, int col1, int col2)
    {

        if (row >= nrow)
        {
            return 0;
        }

        if (memo[row][col1][col2] != -1)
        {
            return memo[row][col1][col2];
        }
        int cherry = grid[row][col1]; // r1
        if (col2 != col1)
        {
            cherry += grid[row][col2];
        }

        int maximum = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newRowCommon = row + 1;
                int newcolRobot1 = col1 + i;
                int newcolRobot2 = col2 + j;

                if (newcolRobot1 >= 0 && newcolRobot1 < mcol &&
                    newcolRobot2 >= 0 && newcolRobot2 < mcol)
                    maximum = max(maximum, findmax(grid, newRowCommon,
                                                   newcolRobot1, newcolRobot2));
            }
        }
        return memo[row][col1][col2] = cherry + maximum;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        nrow = grid.size(), mcol = grid[0].size();
        memset(memo, -1, sizeof(memo));
        return findmax(grid, 0, 0, mcol - 1);
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    return 0;
}