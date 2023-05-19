#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (color[i])
            continue;
        color[i] = 1;
        for (q.push(i); !q.empty(); q.pop())
        {
            int cur = q.front();
            for (int neighbor : graph[cur])
            {
                if (!color[neighbor])
                {
                    color[neighbor] = -color[cur];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[cur])
                    return false;
            }
        }
    }
    return true;
}
// Function to build an undirected graph
vector<vector<int>> buildGraph(const vector<vector<int>> &data)
{
    int numVertices = data.size();
    vector<vector<int>> graph(numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        for (int j : data[i])
        {
            graph[i].push_back(j); // Add edges from vertex i to its adjacent vertices
            graph[j].push_back(i); // Since the graph is undirected, add edges in both directions
        }
    }

    return graph;
}

int main()
{
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    vector<vector<int>> undirectedGraph = buildGraph(graph);

    // Displaying the adjacency list representation of the undirected graph
    for (int i = 0; i < undirectedGraph.size(); i++)
    {
        cout << "Adjacent vertices of vertex " << i << ": ";
        for (int j : undirectedGraph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}