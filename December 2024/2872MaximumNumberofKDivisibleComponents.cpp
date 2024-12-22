#include <bits/bits-stdc++.h>
using namespace std;

int dfs(int currentNode, int previousNode, unordered_map<int, vector<int>> &graph, vector<int> &values, int k, int &count)
{
    int sum = 0;

    for (auto &neigh : graph[currentNode])
    {
        if (neigh != previousNode)
            sum += dfs(neigh, currentNode, graph, values, k,
                       count);
        sum %= k;
    }
    sum += values[currentNode];

    sum %= k;
    if (sum == 0)
        count++;

    return sum;
}

int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    int count = 0;

    dfs(0, -1, graph, values, k, count);

    return count;
}
int main()
{
    int n = 5, k = 6;
    vector<vector<int>> edg = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> val = {1, 8, 1, 4, 4};
    maxKDivisibleComponents(n, edg, val, k);
    return 0;
}