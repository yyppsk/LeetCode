#include <bits/bits-stdc++.h>
using namespace std;

long long maximumImportance(int n, vector<vector<int>> &roads)
{
    vector<long long> degree(n, 0);

    for (int i = 0; i < roads.size(); i++)
    {
        degree[roads[i][0]]++;
        degree[roads[i][1]]++;
    }

    sort(degree.begin(), degree.end());

    long long totalImportance = 0;
    int assign = 1;
    for (int i = 0; i < degree.size(); i++)
    {
        totalImportance += (degree[i] * assign++);
    }

    return totalImportance;
}

int main()
{
    int n = 5;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};

    cout << maximumImportance(n, roads);
    return 0;
}