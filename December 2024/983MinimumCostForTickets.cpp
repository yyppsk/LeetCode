#include <bits/bits-stdc++.h>
using namespace std;
int mini = INT_MAX;
int findstuff(vector<int> &days, vector<int> &costs, int range, int idx)
{
    int result = 0;
    if (range >= days[idx])
    {
        mini = min(result, mini);
        return 0;
    }
    if (idx >= days.size())
    {
        mini = min(result, mini);
        return 0;
    }
    if (days[idx] > range)
    {
        // option 1

        cout << days[idx] << ">" << range << "\n";

        if (days[idx] + 1 > range)
        {
            result += costs[0];
            findstuff(days, costs, range + 1, idx + 1);
        }
        // option 2
        if (days[idx] + 7 > range)
        {
            result += costs[1];
            findstuff(days, costs, range + 7, idx + 1);
        }
        // option 3
        if (days[idx] + 30 > range)
        {
            result += costs[2];
            findstuff(days, costs, range + 30, idx + 1);
        }
    }
    else
    {
        return 0;
    }

    return 0;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int range = 0;
    findstuff(days, costs, range, 0);
    cout << mini;
}
int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};

    mincostTickets(days, costs);
    return 0;
}