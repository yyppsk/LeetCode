#include <bits/bits-stdc++.h>
using namespace std;
int smallestDistancePairV1(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> distance;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            distance.push(abs(nums[i] - nums[j]));
        }
    }

    for (int step = 1; step <= k; step++)
    {
        distance.pop();
    }

    return distance.top();
}
int smallestDistancePair(std::vector<int> &nums, int k)
{
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    int l = 0;
    int r = nums[n - 1] - nums[0];

    while (l < r)
    {
        int m = l + (r - l) / 2;
        int cnt = 0;

        for (int i = 0, j = 0; i < n; ++i)
        {
            while (j < n && nums[j] <= nums[i] + m)
                ++j;
            cnt += j - i - 1;
        }

        if (cnt < k)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return l;
}
int main()
{
    return 0;
}