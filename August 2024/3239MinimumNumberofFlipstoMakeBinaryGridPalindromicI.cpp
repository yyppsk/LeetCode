#include <bits/bits-stdc++.h>
using namespace std;
int minFlips(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // row wise
    int rowWise = 0;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;
        while (low < high)
        {
            if (grid[i][low] != grid[i][high])
            {
                rowWise += 1;
            }
            low++, high--;
        }
    }

    int columnWise = 0;
    for (int i = 0; i < m; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {

            if (grid[low][i] != grid[high][i])
            {
                columnWise += 1;
            }
            low++, high--;
        }
    }

    return min(rowWise, columnWise);
}
int main()
{
    vector<vector<int>> grid = {{0, 1}, {0, 1}, {0, 0}};
    minFlips(grid);
    return 0;
}