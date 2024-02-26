#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination)
    {
        if (n == 1)
            return true;
        vector<int> adj[n];

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        q.push(source);
        unordered_set<int> visited;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();
            visited.insert(currNode);
            if (currNode == destination)
                return true;
            // explore
            for (auto &neigh : adj[currNode])
            {
                // Only push unvisited neighbors to avoid cycles
                if (!visited.count(neigh))
                {
                    visited.insert(neigh);
                    q.push(neigh);
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int n = 6, source = 0, destination = 5;

    cout << obj.validPath(n, edges, source, destination);

    return 0;
}