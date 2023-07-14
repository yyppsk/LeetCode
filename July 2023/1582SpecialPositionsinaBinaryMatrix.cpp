#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
/* Test 1

    set<int> targetRows, targetCols;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                targetCols.insert(j);
                targetRows.insert(i);
            }
        }
    }
    int cnt = 0, result = 0;
    for (auto const &ele : targetCols)
    {
        cnt = 0;
        for (int k = 0; k < mat.size(); k++)
        {
            if (mat[k][ele] == 1)
            {
                ++cnt;
            }
        }
        if (cnt == 1)
            result++;
    }
*/
int numSpecial(vector<vector<int>> &mat)
{
    vector<int> rows(mat.size()), cols(mat[0].size());
    vector<pair<int, int>> coord;
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j)
        {
            if (mat[i][j])
            {
                coord.push_back({i, j});
                ++rows[i], ++cols[j];
            }
        }
    for (auto i : rows)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : cols)
    {
        cout << i << " ";
    }
    cout << endl;
    int res = 0;
    for (pair<int, int> const &ele : coord)
    {
        if (mat[ele.first][ele.second] && rows[ele.first] == 1 && cols[ele.second] == 1)
            ++res;
    }

    return res;
}
int main()
{
    vector<vector<int>> mat({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    });
    cout << numSpecial(mat);
    return 0;
}