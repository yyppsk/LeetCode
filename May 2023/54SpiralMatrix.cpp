#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // track left and rights, ups and downs
    vector<int> result;
    int row = matrix.size(), col = matrix[0].size();
    int left = 0, right = col - 1, up = 0, down = row - 1;
    while (result.size() < row * col)
    {
        for (int j = left; j <= right && result.size() < row * col; j++)
            result.push_back(matrix[up][j]);
        for (int i = up + 1; i <= down - 1 && result.size() < row * col; i++)
            result.push_back(matrix[i][right]);
        for (int j = right; j >= left && result.size() < row * col; j--)
            result.push_back(matrix[down][j]);
        for (int i = down - 1; i >= up + 1 && result.size() < row * col; i--)
            result.push_back(matrix[i][left]);
        left++, right--, up++, down--;
    }

    return result;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    spiralOrder(matrix);
    return 0;
}