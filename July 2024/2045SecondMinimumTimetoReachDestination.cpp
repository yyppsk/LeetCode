#include <bits/bits-stdc++.h>
using namespace std;

int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
{
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> time1(n + 1, INT_MAX);
    vector<int> time2(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    time1[0] = 0;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int elapsedTime = node.first;
        int currentNode = node.second;
        if (currentNode == n && time2[n] != INT_MAX)
        {

            return time2[n];
        }

        int zone = elapsedTime / change;
        if (zone % 2 == 1)
        {
            // red
            elapsedTime = change * (zone + 1); // next green
        }
        for (auto &neighbour : graph[currentNode])
        {

            int newTime = elapsedTime + time;

            if (newTime < time1[neighbour])
            {
                time2[neighbour] = time1[neighbour];
                time1[neighbour] = newTime;
                pq.push({newTime, neighbour});
            }
            else if (newTime < time2[neighbour] && time1[neighbour] != newTime)
            {
                time2[neighbour] = newTime;
                pq.push({newTime, neighbour});
            }
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> e = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    int n = 5, time = 3, change = 5;

    cout << secondMinimum(n, e, time, change);
    return 0;
}