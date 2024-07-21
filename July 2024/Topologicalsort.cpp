#include <bits/bits-stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
{

    vis[node] = 1;
    for (auto &neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, vis, st, adj);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> result;

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}
int main()
{
    return 0;
}