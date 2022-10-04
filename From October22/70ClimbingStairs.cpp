#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int climbStairsRec(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return climbStairsRec(n - 1) + climbStairsRec(n - 2);
}
int climbStairsMem(int n, vector<int> &dp)
{

    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != 0)
        return dp[n];
    else
    {
        dp[n] = climbStairsMem(n - 1, dp) + climbStairsMem(n - 2, dp);
        return dp[n];
    }
}
int main()
{
    int n = 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    cout << climbStairsMem(n, dp) << endl;
    return 0;
}