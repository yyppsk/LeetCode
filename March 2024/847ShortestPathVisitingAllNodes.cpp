#include <bits/stdc++.h>
using namespace std;

int min = INT_MAX;
void findShortest(vector<int> *adj, int size, int src)
{

    queue < int
    // for (int i = 0; i < size; i++)
    // {
    //     cout << i << " : ";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> adj[n];

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[i].push_back(graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Src : " << i << "\n";
        findShortest(adj, n, i);
    }

    return 0;
}

int main()
{
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    cout << shortestPathLength(graph);
    return 0;
}