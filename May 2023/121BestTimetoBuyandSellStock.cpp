#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxProfit(vector<int> &prices)
{
    // 199 / 211 Brute Force
    /*
    int profit = INT_MIN;
    for (int day = 0; day < prices.size(); day++)
    {
        for (int otherday = day + 1; otherday < prices.size(); otherday++)
        {
            printf("Buy at Day %d stock at price %d\nSell that stock at %d : Margin (%d)\n", day, prices[day], prices[otherday], prices[otherday] - prices[day]);
            profit = max(profit, prices[otherday] - prices[day]);
        }
    }
    if (profit < 0)
        return 0;
    return profit;
    */
    // Kadane & Maintain minimum along with traversal, Striver
    int mini = prices[0], profit = 0;
    for (int day = 1; day < prices.size(); day++)
    {
        int selling = prices[day] - mini;
        profit = max(profit, selling);
        mini = min(mini, prices[day]);
    }
    return profit;
}
int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices);
    return 0;
}