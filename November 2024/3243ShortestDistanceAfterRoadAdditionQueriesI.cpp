#include <bits/bits-stdc++.h>
using namespace std;

int findDistance(unordered_map<int, vector<int>> &edges, int n)
{
    int min_distance = INT_MAX;
    unordered_set<int> vis;
    queue<pair<int, int>> q;

    q.push({0, 0});
    vis.insert(0);

    while (!q.empty())
    {
        auto [curr, dist] = q.front();
        q.pop();

        if (curr == n - 1)
        {
            return dist;
        }

        for (auto &neighbour : edges[curr])
        {
            if (vis.find(neighbour) == vis.end())
            {
                vis.insert(neighbour);
                q.push({neighbour, dist + 1});
            }
        }
    }

    return -1;
}

vector<int> shortestDistanceAfterQueries(int n,
                                         vector<vector<int>> &queries)
{
    unordered_map<int, vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        edges[i].push_back(i + 1);
    }

    vector<int> distance;
    for (int i = 0; i < queries.size(); i++)
    {
        edges[queries[i][0]].push_back(queries[i][1]);
        distance.push_back(findDistance(edges, n));
    }
    return distance;
}

// Optimized BFS
int findDistance(vector<vector<int>> &edges, int n)
{
    vector<bool> vis(n, false);
    queue<pair<int, int>> q;

    q.push({0, 0});
    vis[0] = true;

    while (!q.empty())
    {
        auto [curr, dist] = q.front();
        q.pop();

        if (curr == n - 1)
        {
            return dist;
        }

        for (auto &neighbour : edges[curr])
        {
            if (!vis[neighbour])
            {
                vis[neighbour] = true;
                q.push({neighbour, dist + 1});
            }
        }
    }

    return -1;
}

vector<int> shortestDistanceAfterQueries(int n,
                                         vector<vector<int>> &queries)
{
    vector<vector<int>> edges(n);

    for (int i = 0; i < n - 1; i++)
    {
        edges[i].push_back(i + 1);
    }

    // Compute distances for each query
    vector<int> distance;
    for (auto &query : queries)
    {
        edges[query[0]].push_back(query[1]);
        distance.push_back(findDistance(edges, n));
    }

    return distance;
}

int main()
{
    int n = 5;
    vector<vector<int>> q = {{2, 4}, {0, 2}, {0, 4}};
    shortestDistanceAfterQueries(n, q);
    return 0;
}