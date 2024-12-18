#include <bits/bits-stdc++.h>
using namespace std;
vector<int> finalPrices_brute(vector<int> &prices)
{
    for (int i = 0; i < prices.size(); i++)
    {
        int fixed = prices[i];
        int minn = INT_MAX;
        for (int j = i + 1; j < prices.size(); j++)
        {

            if (prices[j] <= prices[i])
            {
                minn = min(minn, j);
                break;
            }
        }
        if (minn != INT_MAX)
            prices[i] -= prices[minn];
    }
    return prices;
}

// stack

vector<int> finalPrices(vector<int> &prices)
{
    stack<int> st;
    vector<int> result(prices.begin(), prices.end());
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() > prices[i])
        {
            st.pop();
        }
        if (!st.empty())
            result[i] = prices[i] - st.top();
        st.push(prices[i]);
    }
    return result;
}
int main()
{
    return 0;
}