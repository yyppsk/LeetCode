#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    if (mat.size() * mat[0].size() != r * c)
        return mat;
    vector<vector<int>> ans(r, vector<int>(c, 0));
    int trackR = 0, trackC = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            ans[trackR][trackC] = mat[i][j];
            trackC++;
            if (trackC == c)
            {
                trackC = 0;
                trackR++;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main()
{
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    matrixReshape(nums, 1, 4);
    return 0;
}