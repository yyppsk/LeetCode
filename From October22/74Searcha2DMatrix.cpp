#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;
    int n = matrix.size();
    
}
int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    searchMatrix(arr, 3);
    return 0;
}