#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> floydWarshal(vector<char> &original,
                                       vector<char> &changed,
                                       vector<int> &cost)
{
    vector<vector<long long>> costForPairs(26,
                                           vector<long long>(26, INT_MAX));

    for (int i = 0; i < original.size(); i++)
    {
        costForPairs[original[i] - 'a'][changed[i] - 'a'] =
            min(costForPairs[original[i] - 'a'][changed[i] - 'a'],
                (long long)cost[i]);
    }

    for (int via = 0; via < 26; via++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                costForPairs[i][j] =
                    min(costForPairs[i][j],
                        costForPairs[i][via] + costForPairs[via][j]);
            }
        }
    }

    return costForPairs;
}

long long minimumCost(string source, string target, vector<char> &original,
                      vector<char> &changed, vector<int> &cost)
{
    vector<vector<long long>> costOfPairs =
        floydWarshal(original, changed, cost);

    long long finalCost = 0;
    for (int i = 0; i < source.length(); i++)
    {
        if (source[i] == target[i])
        {
            continue;
        }
        if (costOfPairs[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
        {
            return -1;
        }
        finalCost += costOfPairs[source[i] - 'a'][target[i] - 'a'];
    }

    return finalCost;
}

int main()
{
    string source = "aaaabadaaa";
    string target = "dbdadddbad";
    vector<char> original = {'c', 'a', 'c', 'a', 'a', 'b', 'b', 'b', 'd', 'd', 'c'};
    vector<char> changed = {'a', 'c', 'b', 'd', 'b', 'c', 'a', 'd', 'c', 'b', 'd'};
    vector<int> cost = {7, 8, 11, 9, 7, 6, 4, 6, 9, 5, 9};

    cout << minimumCost(source, target, original, changed, cost);
    return 0;
}
