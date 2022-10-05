#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int countNegatives(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << " ";
            grid[i][j] < 0 ? count++ : count;
        }
        cout << endl;
    }
    return count;
}
int countNegatives2(vector<vector<int>> &grid)
{
    int count = 0;
    int nextEnd = grid[0].size() - 1;

    for (int i = 0; i < grid.size(); i++)
    {
        int start = 0, end = grid[0].size();
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (grid[i][start] < 0)
                ;
        }
    }
}
int main()
{
    vector<vector<int>> arr = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << countNegatives(arr);
    return 0;
}