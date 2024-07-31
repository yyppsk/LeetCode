#include <bits/bits-stdc++.h>
using namespace std;
int minOperations(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    int operations = 0;
    while (!pq.empty())
    {
        if (pq.top() >= k)
        {
            return operations;
        }
        pq.pop();
        operations++;
    }

    return operations;
}
int main()
{

    return 0;
}