#include <bits/bits-stdc++.h>
using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
    priority_queue<long long> pq;

    for (const auto &ele : nums)
    {
        pq.push(ele);
    }

    long long score = 0;

    while (k--)
    {
        double current = pq.top();
        score += current;
        double transform = (ceil(current / 3));
        pq.pop();
        pq.push(transform);
    }
    return score;
}

int main()
{
    vector<int> nums = {1, 10, 3, 3, 3};
    int k = 3;

    cout << maxKelements(nums, k) << "\n";

    return 0;
}