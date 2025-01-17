#include <bits/bits-stdc++.h>
using namespace std;
//  BRUTE FORCE 64 / 74 testcases passed
class Solution
{
public:
    int bfs(int &node, unordered_map<int, vector<int>> graph, int &n)
    {
        queue<int> q;
        vector<int> distance(n, 0);
        vector<bool> visited(n, false);
        int sum = 0;

        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            sum += distance[current];

            for (int neighbor : graph[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    distance[neighbor] += distance[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        return sum;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }

        vector<int> result(n);

        for (int i = 0; i < n; ++i)
        {
            result[i] = bfs(i, graph, n);
        }

        return result;
    }
};

class Solution_2
{
public:
    int bfs(int &node, unordered_map<int, vector<int>> graph, int &n)
    {
        queue<int> q;
        vector<int> distance(n, 0);
        vector<bool> visited(n, false);
        int sum = 0;

        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            sum += distance[current];

            for (int neighbor : graph[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    distance[neighbor] += distance[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        return sum;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }

        vector<int> result(n);

        for (int i = 0; i < n; ++i)
        {
            result[i] = bfs(i, graph, n);
        }

        return result;
    }
};
int main()
{
    return 0;
}