#include <bits/bits-stdc++.h>
using namespace std;

// TC N*M
int maximumPopulation(vector<vector<int>> &logs)
{
    vector<int> years(100, 0);

    for (int i = 0; i < logs.size(); i++)
    {
        for (int j = logs[i][0] - 1950; j < logs[i][1] - 1950; j++)
        {
            years[j] += 1;
        }
    }

    int minYear = INT_MAX, maxVal = -1;
    for (int i = 0; i < years.size(); i++)
    {
        if (years[i] > maxVal)
        {
            maxVal = years[i];
            minYear = i + 1950;
        }
    }

    return minYear;
}

// Optimise
int maximumPopulation(vector<vector<int>> &logs)
{
    vector<int> years(101, 0);

    for (int i = 0; i < logs.size(); i++)
    {
        years[logs[i][0] - 1950] += 1; // start
        years[logs[i][1] - 1950] -= 1; // end
    }

    int minYear = 1950, maxVal = years[0];
    for (int i = 1; i < years.size(); i++)
    {
        years[i] += years[i - 1];
        if (years[i] > maxVal)
        {
            maxVal = years[i];
            minYear = i + 1950;
        }
    }

    return minYear;
}

int main()
{
    vector<vector<int>> logs = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
    maximumPopulation(logs);
    return 0;
}