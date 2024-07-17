#include <bits/bits-stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq;

    for (const auto &ele : piles)
    {
        pq.push(ele);
    }

    while (k--)
    {
        int current = pq.top();
        int transform = current - floor(current / 2);
        pq.pop();
        pq.push(transform);
    }

    int sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int minStoneSumBetter(vector<int> &A, int k)
{
    priority_queue<int> pq(A.begin(), A.end());
    int res = accumulate(A.begin(), A.end(), 0);
    while (k--)
    {
        int a = pq.top();
        pq.pop();
        pq.push(a - a / 2);
        res -= a / 2;
    }
    return res;
}
int main()
{
    vector<int> piles = {4, 3, 6, 7};
    int k = 3;

    cout << minStoneSum(piles, k);
    return 0;
}