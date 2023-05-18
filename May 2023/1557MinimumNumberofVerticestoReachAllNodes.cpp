#include <iostream>
#include <vector>

using namespace std;

// Graph class
class Graph
{
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    // Constructor
    Graph(int n)
    {
        numVertices = n;
        adjacencyList.resize(numVertices);
    }

    // Add edge to the graph
    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
    }

    // Print the graph
    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << ": ";
            for (int j : adjacencyList[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<bool> incomingedges(n, false);
    for (int i = 0; i < edges.size(); i++)
    {
        incomingedges[edges[i][1]] = true;
    }
    vector<int> res;
    for (int i = 0; i < incomingedges.size(); i++)
    {
        if (incomingedges[i] == false)
        {
            res.push_back(i);
        }
    }
    return res;
}
int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};

    // Create a graph object
    Graph graph(n);

    // Add edges to the graph
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        graph.addEdge(u, v);
    }

    // Print the graph
    graph.printGraph();
    vector<int> ans = findSmallestSetOfVertices(n, edges);
    for (const auto &i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
