#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto &ele : mp)
        {
            pq.push(ele.second);
        }

        queue<pair<int, int>> task;
        int time = 0;
        while (!task.empty() || !pq.empty())
        {
            ++time;
            if (!pq.empty())
            {
                if (pq.top() > 1)
                    task.push({pq.top() - 1, time + n});
                pq.pop();
            }
            if (!task.empty() && task.front().second == time)
            {
                pq.push(task.front().first);
                task.pop();
            }
        }
        return time;
    }
};
int main()
{
    return 0;
}