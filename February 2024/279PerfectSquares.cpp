#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int solve(int currentn)
{
    if (currentn == 0)
    {
        return 0;
    }
    if (dp[currentn] != -1)
    {
        return dp[currentn];
    }
    int mincount = INT_MAX;
    for (int i = 1; i * i <= currentn; i++)
    {
        int result = 1 + solve(currentn - i * i);
        mincount = min(result, mincount);
    }

    return dp[currentn] = mincount;
}
int numSquares(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n);
}

int main()
{
    cout << numSquares(12) << endl; // Output: 2
    // cout << numSquares(10000) << endl; // Output: 1

    return 0;
}
