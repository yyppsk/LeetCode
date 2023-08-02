#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int bottomUpDp(string &word1, string &word2, int m, int n, vector<vector<int>> &dp)
{
    // Initialize base cases
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i; // Fill Up the
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp[m][n];
}
int recur(string &word1, string &word2, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];

    if (word1[m - 1] == word2[n - 1])
    {
        dp[m - 1][n - 1] = recur(word1, word2, m - 1, n - 1, dp);
        return dp[m - 1][n - 1];
    }
    else
    {
        dp[m - 1][n - 1] = 1 + min(recur(word1, word2, m - 1, n - 1, dp), min(recur(word1, word2, m - 1, n, dp), recur(word1, word2, m, n - 1, dp)));
        return dp[m - 1][n - 1];
    }
}
// int recur2(string &word1, string &word2, int m, int n)
// {
//     if (m == 0)
//         return n;
//     if (n == 0)
//         return m;
//     if (word1[m - 1] == word2[n - 1])
//     {
//         return recur(word1, word2, m - 1, n - 1);
//     }
//     else
//     {
//         return 1 + min(recur(word1, word2, m - 1, n - 1), min(recur(word1, word2, m - 1, n), recur(word1, word2, m, n - 1)));
//     }
// }
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int ans = recur(word1, word2, word1.size(), word2.size(), dp);
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main()
{
    cout << endl;
    cout << minDistance("intention", "execution");
    return 0;
}