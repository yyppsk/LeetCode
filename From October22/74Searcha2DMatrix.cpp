#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;
    int row = matrix.size();
    int col = matrix[0].size();

    int lo = 0;
    int hi = (row * col) - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (matrix[mid / col][mid % col] == target)
            return true;
        if (matrix[mid / col][mid % col] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix(arr, 5);
    return 0;
}