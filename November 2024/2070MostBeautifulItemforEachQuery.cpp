#include <bits/bits-stdc++.h>
using namespace std;

// BRUTE FORCE N^2
vector<int> maximumBeauty_brute(vector<vector<int>> &items, vector<int> &queries)
{

    // For each query I would check if I find some possible/Valid pair

    vector<int> result;
    for (int &query : queries)
    {
        int validAnswer = 0;

        for (int i = 0; i < items.size(); i++)
        {
            // check if my current query is larger or equal to this price pair

            if (query >= items[i][0])
            {
                validAnswer = max(validAnswer, items[i][1]);
            }
        }

        result.push_back(validAnswer);
    }

    return result;
}

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
{

    // For each query I would check if I find some possible/Valid pair

    vector<int> result;

    for (int i = 0; i < items.size(); i++)
    {
        // {P,B} ---> {B,P}
        swap(items[i][0], items[i][1]);
    }

    sort(items.begin(), items.end(), greater<vector<int>>());

    for (int &query : queries)
    {
        int validQuery = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if (query >= items[i][1])
            {
                validQuery = items[i][0];
                break;
            }
        }
        result.push_back(validQuery);
    }

    return result;
}

int main()
{
    vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};

    maximumBeauty(items, queries);
    return 0;
}