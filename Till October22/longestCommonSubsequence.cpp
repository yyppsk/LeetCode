#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int lcsRec(string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (s1[n - 1] == s2[m - 1])
        return 1 + lcsRec(s1, s2, n - 1, m - 1);
    else
        return max(lcsRec(s1, s2, n - 1, m), lcsRec(s1, s2, n, m - 1));
}
int lcsMem(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
    {
        dp[n][m] = 1 + lcsMem(s1, s2, n - 1, m - 1, dp);
        return dp[n][m];
    }
    else
    {
        dp[n][m] = max(lcsMem(s1, s2, n - 1, m, dp), lcsMem(s1, s2, n, m - 1, dp));
    }
    return dp[n][m];
}
int lcsTabulation(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][m];
}
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> s;

        if (k <= 0)
            return false;
        if (k >= nums.size())
            k = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
                s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }

        return false;
    }
};
int main()
{
    // string s1 = "oxcpqrsvwf", s2 = "shmtulqrypy";
    string s1 = "cab", s2 = "dabc";
    // ans = 2
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    vector<vector<int>> tab(s1.size() + 1, vector<int>(s2.size() + 1));
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << endl;
    //     for (int j = 0; j < dp[i].size(); j++)
    //         cout << dp[i][j] << " ";
    // }
    // cout << "\n"
    //      << lcsMem(s1, s2, s1.size(), s2.size(), dp);
    // cout << endl;
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << endl;
    //     for (int j = 0; j < dp[i].size(); j++)
    //         cout << dp[i][j] << " ";
    // }
    cout << "Answer " << lcsTabulation(s1, s2, s1.size(), s2.size(), tab) << endl;
    for (int i = 0; i <= s2.size(); i++)
    {
        tab[0][i] = 0;
    }
    for (int i = 0; i <= s1.size(); i++)
        tab[i][0] = 0;
    for (int i = 0; i < tab.size(); i++)
    {
        cout << endl;
        for (int j = 0; j < tab[i].size(); j++)
            cout << tab[i][j] << " ";
    }
    cout << endl;
    for (int i = 0; i < tab.size(); i++)
    {
        cout << endl;
        for (int j = 0; j < tab[i].size(); j++)
            cout << tab[i][j] << " ";
    }
    return 0;
}