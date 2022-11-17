#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> finalPrices(vector<int> &prices)
{
    // f you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimu
    //  index such that j > i and prices[j] <= prices[i].
    vector<int> res;
    for (int i = 0; i < prices.size(); i++)
    {
        int fixed = prices[i];
        int minn = INT_MAX;
        for (int j = i + 1; j < prices.size(); j++)
        {

            if ((j > i) && (prices[j] <= prices[i]))
            {
                printf("Compare %d with %d\n", fixed, prices[j]);
                minn = min(minn, j);
                cout << "Min index " << minn << endl;
            }
        }
        if (minn != INT_MAX)
            prices[i] -= prices[minn];
    }
    return prices;
}
int main()
{ //  2  3  4
    vector<int> prices = {10, 1, 1, 6};
    vector<int> res = finalPrices(prices);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}