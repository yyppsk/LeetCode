#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto &nodes : flights)
        {
            adj[nodes[0]].push_back({nodes[1], nodes[2]});
        }

        // a normal queue cause priority queue just won't matter here
        queue<pair<int, pair<int, int>>> q;
        //{stops, {node, cost}}
        q.push({0, {src, 0}});

        vector<double> dist(n, 10e9);

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();
            int stops = current.first;
            int node = current.second.first;
            int cost = current.second.second;

            if (stops > k)
            {
                continue;
            }

            for (auto iter : adj[node])
            {
                int adjacentNode = iter.first;
                int edgeWeight = iter.second;

                int newdistance = cost + edgeWeight;
                if (newdistance < dist[adjacentNode] && stops <= k)
                {
                    dist[adjacentNode] = newdistance;
                    q.push({stops + 1, {adjacentNode, newdistance}});
                }
            }
        }
        if (dist[dst] == 10e9)
            return -1;
        return dist[dst];
    }
};
int main()
{
    return 0;
}