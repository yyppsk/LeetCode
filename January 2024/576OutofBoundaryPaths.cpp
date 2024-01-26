#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

vector<pair<int, int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int MOD = 1000000007;
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    if (startRow == m || startColumn == n || startRow < 0 || startColumn < 0)
        return 1;
    if (maxMove == 0)
        return 0;

    int sum = 0; // Reset sum for each function call

    for (auto &dir : delta)
    {
        sum = (sum + findPaths(m, n, maxMove - 1, dir.first + startRow, dir.second + startColumn)) % MOD;
    }

    return sum;
}

class Solution
{
private:
    int dp[52][52][52];
    int mod = 1000000007;
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(int i, int j, int m, int n, int maxMove)
    {
        if (i >= m || i < 0 || j >= n || j < 0)
            return 1;

        if (maxMove <= 0)
            return 0;

        int &ret = dp[i][j][maxMove];

        if (ret != -1)
            return ret;

        ret = 0;

        for (auto move : moves)
            ret = (ret +
                   dfs(i + move.first, j + move.second, m, n, maxMove - 1)) %
                  mod;

        return ret;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {

        // memset(dp, -1, sizeof dp);

        return dfs(startRow, startColumn, m, n, maxMove);
    }
};
int main()
{
    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    cout << "\n"
         << findPaths(m, n, maxMove, startRow, startColumn);
    return 0;
}
