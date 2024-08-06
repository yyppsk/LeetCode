#include <bits/bits-stdc++.h>
using namespace std;
vector<int> processQueries(vector<int> &queries, int m)
{
    vector<int> permutation;

    for (int i = 1; i <= m; i++)
    {
        permutation.push_back(i);
    }

    vector<int> result;
    for (int i = 0; i < queries.size(); i++)
    {
        int to_find = queries[i];

        for (int j = 0; j < permutation.size(); j++)
        {
            if (permutation[j] == to_find)
            {
                result.push_back(j);
                permutation.erase(permutation.begin() + j);
                permutation.emplace(permutation.begin(), to_find);
                break;
            }
        }
    }

    // for (auto &ele : result)
    // {
    //     cout << ele << " ";
    // }
    return result;
}
int main()
{
    vector<int> queries = {3, 1, 2, 1};
    int m = 5;
    processQueries(queries, m);
    return 0;
}