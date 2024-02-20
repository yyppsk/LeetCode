#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
public:
    stack<pair<int, int>> pastSpans;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!pastSpans.empty() && pastSpans.top().first <= price)
        {
            span += pastSpans.top().second;
            pastSpans.pop();
        }
        pastSpans.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main()
{
    return 0;
}