#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    vector<pair<int, int>> delta = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int row = grid.size();
    int col = row;

    vector<vector<int>> res(row - 2, vector<int>(col - 2, 0));
    for (int resultRow = 0; resultRow < row - 2; resultRow++)
    {

        for (int resultCol = 0; resultCol < col - 2; resultCol++)
        {
            int maxi = INT_MIN;
            int centerCordX = resultRow, centerCordY = resultCol;
            centerCordX += 1;
            centerCordY += 1;
            for (auto &pair : delta)
            {
                // cout << "(" << centerCordX << "," << centerCordY << ")" << endl;
                maxi = max(maxi, grid[centerCordX + pair.first][centerCordY + pair.second]);
            }
            res[resultRow][resultCol] = maxi;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return {};
}
int main()
{
    vector<vector<int>> grid = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    largestLocal(grid);
    return 0;
}