#include <bits/bits-stdc++.h>
using namespace std;
int oddCells(int m, int n, vector<vector<int>> &indices)
{
    vector<vector<int>> res(m, vector<int>(n, 0));

    for (auto &edge : indices)
    {
        int r = edge[0];
        int c = edge[1];

        // row
        for (int i = 0; i < n; i++)
        {
            res[r][i] += 1;
        }

        for (int j = 0; j < m; j++)
        {
            res[j][c] += 1;
        }
    }
    int cnt = 0;

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            if (res[i][j] % 2 != 0)
            {
                cnt += 1;
            }
        }
    }
    return cnt;
}
int main()
{
    int m = 2, n = 3;
    vector<vector<int>> indices = {{0, 1},
                                   {1, 1}};
    oddCells(m, n, indices);
    return 0;
}