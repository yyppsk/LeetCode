#include <bits/bits-stdc++.h>
using namespace std;

long long findScore2(vector<int> &nums)
{
    int n = nums.size();
    int marked[1000000] = {0};
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
    }
    long long score = 0;
    while (!pq.empty())
    {
        if (marked[pq.top().second] == 0)
        {
            score += pq.top().first;
            marked[pq.top().second] = 1;

            if (pq.top().second - 1 >= 0)
            {
                marked[pq.top().second - 1] = 1;
            }

            if (pq.top().second + 1 < n)
            {
                marked[pq.top().second + 1] = 1;
            }
            pq.pop();
        }
        else
        {
            pq.pop();
        }
    }

    return score;
}

// using uset
long long findScore(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> marked;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
    }
    long long score = 0;
    while (!pq.empty())
    {
        if (marked.find(pq.top().second) == marked.end())
        {
            score += pq.top().first;
            marked.insert(pq.top().second);

            if (pq.top().second - 1 >= 0)
            {
                marked.insert(pq.top().second - 1);
            }

            if (pq.top().second + 1 < n)
            {
                marked.insert(pq.top().second + 1);
            }
            pq.pop();
        }
        else
        {
            pq.pop();
        }
    }

    return score;
}
int main()
{
    return 0;
}