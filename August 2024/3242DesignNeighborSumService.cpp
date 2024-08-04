#include <bits/bits-stdc++.h>
using namespace std;
class neighborSum
{
public:
    vector<vector<int>> localGrid;
    vector<pair<int, int>> delta = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<pair<int, int>> diagonalDirections = {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}};
    neighborSum(vector<vector<int>> &grid)
    {
        this->localGrid = grid;
    }

    int adjacentSum(int value)
    {
        int totalSum = 0;
        int n = localGrid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < localGrid[i].size(); j++)
            {
                if (localGrid[i][j] == value)
                {
                    for (auto &ele : delta)
                    {
                        int x = ele.first + i;
                        int y = ele.second + j;
                        if (x >= 0 && y >= 0 && x < n && y < n)
                        {
                            totalSum += localGrid[x][y];
                        }
                    }
                }
            }
        }

        return totalSum;
    }

    int diagonalSum(int value)
    {
        int totalSum = 0;
        int n = localGrid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < localGrid[i].size(); j++)
            {
                if (localGrid[i][j] == value)
                {
                    for (auto &ele : diagonalDirections)
                    {
                        int x = ele.first + i;
                        int y = ele.second + j;
                        if (x >= 0 && y >= 0 && x < n && y < n)
                        {
                            totalSum += localGrid[x][y];
                        }
                    }
                }
            }
        }

        return totalSum;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    auto obj1 = new neighborSum(grid);
    cout << obj1->adjacentSum(4);

    return 0;
}