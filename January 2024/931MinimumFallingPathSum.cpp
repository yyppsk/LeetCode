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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> memo(101, vector<int>(101, -1));
        ;
        int row = 0, result = INT_MAX;
        for (int col = 0; col < matrix.size(); col++)
        {
            result = min(result, solve(row, col, matrix, matrix.size(), memo));
        }
        return result;
    }

private:
    int solve(int row, int col, vector<vector<int>> &matrix, int n, vector<vector<int>> &memo)
    {

        if (row == n - 1)
        {
            return matrix[row][col];
        }

        if (memo[row][col] != -1)
        {
            return memo[row][col];
        }
        int sum = matrix[row][col];
        int minSum = INT_MAX;

        if (row + 1 < n && col - 1 >= 0)
            minSum = min(minSum, sum + solve(row + 1, col - 1, matrix, n, memo));
        if (row + 1 < n)
            minSum = min(minSum, sum + solve(row + 1, col, matrix, n, memo));
        if (row + 1 < n && col + 1 < n)
            minSum = min(minSum, sum + solve(row + 1, col + 1, matrix, n, memo));
        return memo[row][col] = minSum;
    }
};

class Solution2
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> copy(n, vector<int>(n));

        for (int col = 0; col < n; col++)
        {
            copy[0][col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {

                int leftDiagonal = INT_MAX;
                int rightDiagonal = INT_MAX;

                if (col - 1 >= 0)
                    leftDiagonal = copy[row - 1][col - 1];

                int aboveRow = copy[row - 1][col];

                if (col + 1 < n)
                    rightDiagonal = copy[row - 1][col + 1];

                copy[row][col] = matrix[row][col] +
                                 min({leftDiagonal, aboveRow, rightDiagonal});
            }
        }

        int res = INT_MAX;
        for (int col = 0; col < n; col++)
        {
            res = min(res, copy[n - 1][col]);
        }
        return res;
    }
};
int main()
{
    return 0;
}