#include <bits/bits-stdc++.h>
using namespace std;

pair<int, int> findFarthestNode(int n, unordered_map<int, vector<int>> &adjList,
                                int sourceNode)
{
    queue<int> nodesQueue;
    vector<bool> visited(n, false);

    nodesQueue.push(sourceNode);
    visited[sourceNode] = true;

    int maximumDistance = 0, farthestNode = sourceNode;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        for (int i = 0; i < size; ++i)
        {
            int currentNode = nodesQueue.front();
            nodesQueue.pop();

            farthestNode = currentNode;

            for (int neighbor : adjList[currentNode])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
        }
        if (!nodesQueue.empty())
            maximumDistance++;
    }
    return {farthestNode, maximumDistance};
}

int undirectedTreeDiameter(vector<vector<int>> &edges)
{
    int n = edges.size();

    unordered_map<int, vector<int>> adjList;
    unordered_set<int> vis;

    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    auto [farthestNode, maximumDistance] = findFarthestNode(n, adjList, 0);
    auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
    return diameter;
}
int main()
{
    return 0;
}