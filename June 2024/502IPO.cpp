#include <bits/bits-stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int raisedCapital = w;

    vector<pair<int, int>> projects(profits.size());
    for (int i = 0; i < profits.size(); i++)
    {
        projects[i] = {capital[i], profits[i]};
    }

    sort(projects.begin(), projects.end());

    int i = 0;
    priority_queue<int> pq;

    while (k--)
    {
        while (i < projects.size() && projects[i].first <= raisedCapital)
        {
            pq.push(projects[i].second);
            i++;
        }
        if (pq.empty())
        {
            break;
        }

        raisedCapital += pq.top();
        pq.pop();
    }

    return raisedCapital;
}
int main()
{
    int k = 1, w = 2;

    vector<int> profits = {1, 5, 3}, capital = {1, 1, 2};

    cout << findMaximizedCapital(k, w, profits, capital);
    return 0;
}