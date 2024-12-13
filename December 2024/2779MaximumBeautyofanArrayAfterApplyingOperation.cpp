#include <bits/bits-stdc++.h>
using namespace std;

// deque
int maximumBeauty_deque(vector<int> &nums, int k)
{
    vector<pair<int, int>> intervals;
    for (int i = 0; i < nums.size(); i++)
    {
        intervals.push_back({nums[i] - k, nums[i] + k});
    }

    sort(intervals.begin(), intervals.end());
    deque<pair<int, int>> dq;

    int result = 0;

    for (int i = 0; i < intervals.size(); i++)
    {
        while (!dq.empty() && dq.front().second < intervals[i].first)
        {
            dq.pop_front();
        }

        dq.push_back({intervals[i].first, intervals[i].second});
        result = max(result, (int)dq.size());
    }

    return result;
}

// queue
int maximumBeauty_queue(vector<int> &nums, int k)
{
    vector<pair<int, int>> intervals;
    for (int i = 0; i < nums.size(); i++)
    {
        intervals.push_back({nums[i] - k, nums[i] + k});
    }

    sort(intervals.begin(), intervals.end());
    queue<int> que;

    int result = 0;

    for (int i = 0; i < intervals.size(); i++)
    {
        while (!que.empty() && que.front() < intervals[i].first)
        {
            que.pop();
        }

        que.push(intervals[i].second);
        result = max(result, (int)que.size());
    }

    return result;
}
int main()
{
    return 0;
}