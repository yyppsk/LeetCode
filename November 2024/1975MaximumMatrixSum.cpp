#include <bits/bits-stdc++.h>
using namespace std;
long long maxMatrixSum(vector<vector<int>> &matrix)
{
    long long absoluteSum = 0;
    int negativeValues = 0;
    int minAbsValue = INT_MAX;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] < 0)
            {
                negativeValues += 1;
            }
            minAbsValue = min(minAbsValue, abs(matrix[i][j]));
            absoluteSum += abs(matrix[i][j]);
        }
    }

    if (negativeValues % 2 == 0)
    {
        return absoluteSum;
    }
    return absoluteSum - (2 * minAbsValue);
}
int main()
{
    vector<vector<int>> mat = {{1, -1}, {-1, 1}};
    maxMatrixSum(mat);
    return 0;
}