#include <bits/bits-stdc++.h>
using namespace std;

int m, n;

int checkSquare(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 0;
    }

    if (matrix[i][j] == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = checkSquare(i, j + 1, matrix, dp);
    int down = checkSquare(i + 1, j, matrix, dp);
    int diag = checkSquare(i + 1, j + 1, matrix, dp);

    return dp[i][j] = 1 + min({right, down, diag});
}

int countSquares(vector<vector<int>> &matrix)
{
    m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                answer += checkSquare(i, j, matrix, dp);
            }
        }
    }
    return answer;
}
int main()
{
    return 0;
}