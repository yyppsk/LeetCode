#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void findMax(vector<int> &prices, int &minPrice, int &maxProfit, int idx)
{
    // base case
    if (idx == prices.size())
        return;
    if (prices[idx] < minPrice)
        minPrice = prices[idx];
    int todaysProfit = prices[idx] - minPrice;
    if (todaysProfit > maxProfit)
        maxProfit = todaysProfit;
    findMax(prices, minPrice, maxProfit, idx + 1);
}
int maxProfit(vector<int> &prices)
{
    int maxProfit = INT_MIN, minPrice = INT_MAX;
    findMax(prices, minPrice, maxProfit, 0);
    return maxProfit;
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}