#include <bits/bits-stdc++.h>
using namespace std;

// BFS
vector<vector<int>> buildAdjList(int size, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(size);
    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    return adjList;
}

pair<int, int> findFarthestNode(int n, vector<vector<int>> &adjList,
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
                // Explore neighbors
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
int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                              vector<vector<int>> &edges2)
{
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> adjList1 = buildAdjList(n, edges1);
    vector<vector<int>> adjList2 = buildAdjList(m, edges2);

    int diameter1 = findDiameter(n, adjList1);
    int diameter2 = findDiameter(m, adjList2);

    int combinedDiameter =
        ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

    return max({diameter1, diameter2, combinedDiameter});
}

int findDiameter(int n, vector<vector<int>> &adjList)
{
    auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

    auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
    return diameter;
}

int main()
{
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}}, edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};

    minimumDiameterAfterMerge(edges1, edges2);
    return 0;
}