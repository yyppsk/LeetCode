#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int uniquePathsWithObstaclesSpace(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> dp(n, -1);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            int up, left = 0;
            if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
                temp[j] = 0;
            else if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                if (i > 0)
                    up = dp[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}
int mod = (int)(1e9 + 7);
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up, left = 0;
            if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{
    return 0;
}