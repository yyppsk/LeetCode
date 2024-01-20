#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class SubrectangleQueries
{
public:
    vector<vector<int>> result;
    SubrectangleQueries(vector<vector<int>> &rectangle) { result = rectangle; }

    void updateSubrectangle(int row1, int col1, int row2, int col2,
                            int newValue)
    {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                result[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) { return result[row][col]; }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
int main()
{
    return 0;
}