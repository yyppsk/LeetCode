#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
{
    vector<vector<vector<pair<int, int>>>> helper;
    // vec ( vec ( vec [ {onesRowi} , {onesColj}, {zerosRowi} , {zerosColj}]))
    for (int i = 0; i < grid.size(); i++)
    {
        int onesRowi = 0, onesColj = 0, zerosRowi = 0, zerosColj = 0;
        for (int j = 0; j < grid[0].size(); j++)
        {
                }
    }
}
int main()
{
    vector<vector<int>> gr = {{0, 1, 1},
                              {1, 0, 1},
                              {0, 0, 1}};
    onesMinusZeros(gr);
    return 0;
}