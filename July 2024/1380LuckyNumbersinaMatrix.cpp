#include <bits/bits-stdc++.h>
using namespace std;

/*
///TWO WAY TRAVERSAL

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int i = 0; i < matrix[row].size(); i++)
        {
            cout << matrix[row][i] << " ";
        }
        cout << "\n";
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[j][row] << " ";
        }
        cout << "\n";
    }


*/
vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    const int colSize = matrix[0].size();
    int maxCol[colSize] = {0};

    const int rowSize = matrix.size();
    int minRow[rowSize] = {0};

    // column max stuff

    for (int i = 0; i < matrix[0].size(); i++)
    {
        int colMax = INT_MIN;
        for (int j = 0; j < matrix.size(); j++)
        {
            colMax = max(colMax, matrix[j][i]);
        }
        maxCol[i] = colMax;
    }

    // Row Max Stuff

    for (int i = 0; i < matrix.size(); i++)
    {
        int rowMin = INT_MAX;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            rowMin = min(rowMin, matrix[i][j]);
        }
        minRow[i] = rowMin;
    }

    vector<int> luckyNumberList;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == maxCol[j] && matrix[i][j] == minRow[i])
            {
                luckyNumberList.push_back(matrix[i][j]);
            }
        }
    }
    return luckyNumberList;
}
int main()
{
    vector<vector<int>> matrix = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    luckyNumbers(matrix);
    return 0;
}