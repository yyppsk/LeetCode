#include <bits/bits-stdc++.h>
#include <unordered_set>
using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    queue<int> q;
    vector<vector<int>> result(n);

    unordered_map<int, vector<int>> reachable;

    for (int i = 0; i < edges.size(); i++)
    {
        reachable[edges[i][0]].push_back(edges[i][1]);
    }

    for (const auto &ele : reachable)
    {
        cout << ele.first << " : ";
        for (const auto &e : ele.second)
        {
            cout << e << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        q.push(i);

        unordered_set<int> visited;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (const auto &neighbour : reachable[current])
            {
                if (visited.find(neighbour) == visited.end())
                {
                    result[neighbour].push_back(i);
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> edgeList = {{0, 1},
                                    {0, 2},
                                    {0, 3},
                                    {0, 4},
                                    {1, 2},
                                    {1, 3},
                                    {1, 4},
                                    {2, 3},
                                    {2, 4},
                                    {3, 4}};
    getAncestors(n, edgeList);
    return 0;
}