#include <bits/bits-stdc++.h>
using namespace std;
int findChampion(int n, vector<vector<int>> &edges)
{
    vector<int> indegree(n, 0);

    for (auto edge : edges)
    {
        indegree[edge[1]]++;
    }

    int champ = -1, champCount = 0;
    for (int i = 0; i < n; i++)
    {

        if (indegree[i] == 0)
        {
            champCount++;
            champ = i;
        }
    }
    return champCount > 1 ? -1 : champ;
}
int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    findChampion(3, edges);
    return 0;
}