#include <bits/bits-stdc++.h>
using namespace std;

// Approach 1 Reachable Nodes [Not working for Cycles]

void bfs(int v, vector<vector<int>> &graph, unordered_set<int> &vis, unordered_set<int> terminalNodes, bool &isValid)
{
    vis.insert(v);

    queue<int> bfsque;

    bfsque.push(v);

    while (!bfsque.empty())
    {
        int currentNode = bfsque.front();
        bfsque.pop();
        if (terminalNodes.find(currentNode) != terminalNodes.end())
        {
            isValid = true;
            return;
        }
        for (const auto &neighbour : graph[currentNode])
        {
            if (vis.find(neighbour) == vis.end())
            {
                bfsque.push(neighbour);
                vis.insert(neighbour);
            }
        }
    }
}

vector<int> eventualSafeNodes2(vector<vector<int>> &graph)
{
    unordered_set<int> terminalNodes;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i].size() == 0)
        {
            terminalNodes.insert(i);
        }
    }
    vector<int> safeNodes;

    for (int u = 0; u < graph.size(); u++)
    {
        bool isValid = false;
        if (graph[u].size() == 0)
        {

            isValid = true;
        }
        else
        {
            for (int j = 0; j < graph[u].size(); j++)
            {

                int v = graph[u][j];
                unordered_set<int> vis;
                bfs(v, graph, vis, terminalNodes, isValid);
            }
        }

        if (isValid)
        {
            safeNodes.push_back(u);
        }
    }

    for (const auto &ele : safeNodes)
    {
        cout << ele << " ";
    }
}

// Approach 2 DFS + Inrecursion tracking + Cycle Detection

bool checkCycle(int currentNode, vector<bool> &visited, vector<bool> &inRecursion, vector<vector<int>> &graph)
{
    visited[currentNode] = true;
    inRecursion[currentNode] = true;

    for (int &neighbour : graph[currentNode])
    {
        if (visited[neighbour] == false && checkCycle(neighbour, visited, inRecursion, graph) == true)
        {
            return true; // neighbour causes cycle
        }
        else if (inRecursion[neighbour] == true)
        {
            return true;
        }
    }

    inRecursion[currentNode] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> inRecursion(n, false);

    for (int i = 0; i < n; i++)
    {
        checkCycle(i, visited, inRecursion, graph);
    }

    vector<int> safeNodes;
    for (int i = 0; i < inRecursion.size(); i++)
    {
        if (!inRecursion[i])
            safeNodes.push_back(i);
    }

    return safeNodes;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    eventualSafeNodes(graph);
    return 0;
}