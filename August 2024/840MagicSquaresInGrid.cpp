#include <bits/bits-stdc++.h>
using namespace std;

int numMagicSquaresInside(vector<vector<int>> &grid)
{

    unordered_map<int, vector<int>> rowSums;
    for (int i = 0; i < grid.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < grid[i].size(); j++)
        {
            sum += grid[i][j];
            rowSums[i].push_back(sum);
        }
    }
    unordered_map<int, vector<int>> colSums;

    for (int j = 0; j < grid[0].size(); j++)
    {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            sum += grid[i][j];
            colSums[j].push_back(sum);
        }
    }

    int countValid = 0;

    int n = grid.size();
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 2; j <= n - 1; j++)
        {
            unordered_set<int> st;

            bool sumCol = false;
            bool sumRow = false;
            bool diagonalSum = false;

            // Diagonal Right

            int rightDiagonalSum = grid[i][j - 2] + grid[i + 1][j - 1] + grid[i + 2][j];
            int leftDiagonalSum = grid[i][j] + grid[i + 1][j - 1] + grid[i + 2][j - 2];

            if (rightDiagonalSum == leftDiagonalSum)
            {

                diagonalSum = true;
            }

            if (diagonalSum)
            {

                if (j <= 2)
                {

                    if (rowSums[i][j] == rowSums[i + 1][j] && rowSums[i + 1][j] == rowSums[i + 2][j])
                    {
                        sumCol = true;
                    }
                }
                else
                {
                    if ((rowSums[i][j] - rowSums[i][j - 3]) == (rowSums[i + 1][j] - rowSums[i + 1][j - 3]) && (rowSums[i + 1][j] - rowSums[i + 1][j - 3]) == (rowSums[i + 2][j] - rowSums[i + 2][j - 3]))
                    {
                        sumCol = true;
                    }
                }

                if (sumCol == true)
                {

                    if (i == 0)
                    {
                        if (colSums[j - 2][i + 2] == colSums[j - 1][i + 2] && colSums[j - 1][i + 2] == colSums[j][i + 2])
                        {

                            sumRow = true;
                        }
                    }
                    else
                    {

                        if ((colSums[j - 2][i + 2] - colSums[j - 2][i - 1]) == (colSums[j - 1][i + 2] - colSums[j - 1][i - 1]) && (colSums[j - 1][i + 2] - colSums[j - 1][i - 1]) == (colSums[j][i + 2] - colSums[j][i - 1]))
                        {
                            sumRow = true;
                        }
                    }
                }
            }

            if (sumCol == true && sumRow == true && diagonalSum == true)
            {
                bool numberRange = true;

                for (int k = (i - 2 > 0) ? (i - 2) : 0; k <= i + 2; k++)
                {
                    for (int l = j - 2; l <= j; l++)
                    {
                        if (grid[k][l] >= 10 || grid[k][l] <= 0)
                        {
                            numberRange = false;
                        }
                        st.insert(grid[k][l]);
                    }
                }

                if (st.size() < 9 || st.size() > 9)
                {
                    numberRange = false;
                }
                if (numberRange == true)
                    countValid++;
            }
        }
    }

    return countValid;
}

class Solution
{
public:
    bool isMagicGrid(vector<vector<int>> &grid, int r, int c)
    {

        unordered_set<int> st;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.count(num))
                {
                    return false;
                }
                else
                {
                    st.insert(num);
                }
            }
        }

        int commonSum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        for (int i = 0; i < 3; i++)
        {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != commonSum)
            {
                return false;
            }

            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != commonSum)
            {
                return false;
            }
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != commonSum)
        {
            return false;
        }

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != commonSum)
        {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid.size();

        int count = 0;

        for (int i = 0; i <= rows - 3; i++)
        {
            for (int j = 0; j <= cols - 3; j++)
            {
                if (isMagicGrid(grid, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};
int main()
{
    vector<vector<int>> grid = {{6, 6, 0, 2, 10, 3, 2, 9, 7, 6}, {7, 2, 3, 6, 5, 4, 11, 6, 1, 4}, {0, 4, 10, 1, 0, 8, 5, 3, 10, 1}, {4, 2, 5, 8, 9, 2, 4, 9, 8, 10}, {3, 9, 0, 6, 4, 6, 4, 3, 8, 5}, {8, 1, 6, 10, 5, 10, 9, 5, 1, 6}, {7, 8, 4, 11, 3, 7, 2, 7, 6, 5}, {7, 9, 5, 2, 7, 6, 0, 6, 11, 2}, {6, 4, 9, 9, 5, 1, 5, 8, 6, 9}, {8, 1, 2, 4, 3, 8, 10, 1, 1, 7}};
    return 0;
}