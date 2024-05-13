#include <bits/bits-stdc++.h>
using namespace std;
int matrixScore(vector<vector<int>> &grid)
{
    int bitsize = grid[0].size();
    int row = grid.size();
    int col = bitsize;
    for (int i = 0; i < row; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 0; j < col; j++)
            {
                grid[i][j] = !grid[i][j];
            }
        }
    }
    vector<int> numberofzeroes(20);
    for (int i = 0; i < col; i++)
    {
        int zero = 0;
        for (int j = 0; j < row; j++)
        {
            if (grid[j][i] == 0)
            {
                zero++;
            }
        }
        numberofzeroes[i] = zero;
    }

    // for (int i = 0; i < numberofzeroes.size(); i++)
    // {
    //     cout << i << " : " << numberofzeroes[i] << "\n";
    // }

    for (int i = 0; i < col; i++)
    {
        if (numberofzeroes[i] > (row - numberofzeroes[i]))
        {
            for (int j = 0; j < row; j++)
            {

                grid[j][i] = !grid[j][i];
            }
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     int currentNumber = 0;

    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<int> bits(21);

    bits[1] = 1;
    for (int i = 2; i <= 20; ++i)
    {
        bits[i] = bits[i - 1] * 2;
    }
    int totalSum = 0;

    for (int i = 0; i < row; i++)
    {
        int currentNumber = 0;

        for (int j = 0; j < col; j++)
        {
            currentNumber += (grid[i][j] ? bits[bitsize - j] : 0);
        }
        totalSum += currentNumber;
    }
    return totalSum;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 1}, {1, 0, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 0, 1, 0, 1, 1, 0, 0, 0}};
    cout << matrixScore(grid);

    return 0;
}