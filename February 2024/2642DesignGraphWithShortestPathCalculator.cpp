#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int N;
    typedef pair<int, int> P;
    vector<vector<pair<int, int>>>
        adj;
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        N = n;
        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int cost = edges[i][2];

            adj[from].push_back({to, cost});
        }
    }

    void addEdge(vector<int> edge)
    {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];

        adj[from].push_back({to, cost});
    }

    int shortestPath(int node1, int node2)
    {
        vector<int> Dist(N, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> q;

        q.push({0, node1});
        Dist[node1] = 0;

        while (!q.empty())
        {
            int cost = q.top().first;
            int currNode = q.top().second;
            q.pop();

            for (auto &neigh : adj[currNode])
            {
                int node = neigh.first;
                int weight = neigh.second;

                int newPossibleWt = cost + weight;
                if (newPossibleWt < Dist[node])
                {
                    Dist[node] = newPossibleWt;
                    q.push({Dist[node], node});
                }
            }
        }

        return Dist[node2];
    }
};
int main()
{
    return 0;
}