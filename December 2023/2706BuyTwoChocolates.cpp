#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int buyChoco(vector<int> &prices, int money)
{
    // do not make the stuff negative, min price to be spent
    sort(prices.begin(), prices.end());
    if (money - (prices[0] + prices[1]) >= 0)
    {
        return money - (prices[0] + prices[1]);
    }
    return money;
}
int main()
{
    vector<int> prices = {1, 2, 2};
    int money = 3;
    cout << buyChoco(prices, money);
    return 0;
}