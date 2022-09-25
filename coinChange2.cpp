#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void change2(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (auto i : dp)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] += dp[i - coin];
            printf("Coin : %d\ni:%d\ndp[%d] = %d\n", coin, i, i, dp[i]);
            for (auto i : dp)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    for (auto i : dp)
    {
        cout << i << " ";
    }
    cout << dp[amount] << endl;
}
void change(vector<int> &coins, int amount, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i < amount + 1; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }
    // 1st row becomes Infinite but with condition of division by coin[0]
    for (int i = 1; i < amount + 1; i++)
    {
        if (i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = INT_MAX - 1;
    }
    // DP checking
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\nAnswer :" << dp[n][amount];
}
int main()
{
    vector<int> arr = {1, 2, 5};
    int amount = 5;
    // change(arr, amount, arr.size());
    change2(amount, arr);
    return 0;
}