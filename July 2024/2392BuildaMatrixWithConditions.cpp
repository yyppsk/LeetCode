#include <bits/bits-stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj, stack<int> &st, bool &cycle)
{
    vis[node] = 1; // visiting

    for (int &neighbour : adj[node])
    {
        if (vis[neighbour] == 0)
        {
            dfs(neighbour, vis, adj, st, cycle);
        }

        else if (vis[neighbour] == 1)
        {
            cycle = true;
            return;
        }
    }

    vis[node] = 2;
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &conditions, int k)
{
    unordered_map<int, vector<int>> adj;
    for (vector<int> &edge : conditions)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    vector<int> vis(k + 1, 0);
    stack<int> st;
    vector<int> order;
    bool cycle = false;

    for (int node = 1; node <= k; node++)
    {
        if (vis[node] == 0)
        {
            dfs(node, vis, adj, st, cycle);
            if (cycle)
                return {};
        }
    }

    while (!st.empty())
    {
        order.push_back(st.top());
        st.pop();
    }

    return order;
}
vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    vector<int> toplogicalOrderRow = topologicalSort(rowConditions, k);
    vector<int> toplogicalOrderCol = topologicalSort(colConditions, k);

    if (toplogicalOrderCol.empty() || toplogicalOrderRow.empty())
    {
        return {};
    }

    vector<vector<int>> matrix(k, vector<int>(k, 0));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (toplogicalOrderRow[i] == toplogicalOrderCol[j])
            {
                matrix[i][j] = toplogicalOrderRow[i];
            }
        }
    }

    return matrix;
}
int main()
{
    int k = 3;
    vector<vector<int>> rowConditions = {{1, 2}, {3, 2}}, colConditions = {{2, 1}, {3, 2}};

    buildMatrix(k, rowConditions, colConditions);
    return 0;
}