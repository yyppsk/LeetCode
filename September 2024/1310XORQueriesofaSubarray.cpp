#include <bits/bits-stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        ios::sync_with_stdio(false);
        ios_base::sync_with_stdio(false);
        ios::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);

        vector<int> result;

        for (int i = 1; i < arr.size(); ++i)
        {
            arr[i] ^= arr[i - 1];
        }
        for (const auto &query : queries)
        {
            if (query[0] > 0)
            {
                result.push_back(arr[query[0] - 1] ^ arr[query[1]]);
            }
            else
            {
                result.push_back(arr[query[1]]);
            }
        }

        return result;
    }
};

class Solution2
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> answer;
        unordered_map<int, unordered_map<int, int>> precal;
        for (int i = 0; i < queries.size(); i++)
        {
            int x = 0;
            if (precal.find(queries[i][0]) != precal.end() &&
                precal[queries[i][0]].find(queries[i][1]) !=
                    precal[queries[i][0]].end())
            {
                answer.push_back(precal[queries[i][0]][queries[i][1]]);
            }
            else
            {

                for (int j = queries[i][0]; j <= queries[i][1]; j++)
                {
                    x ^= arr[j];
                }
                precal[queries[i][0]][queries[i][1]] = x;
                answer.push_back(x);
            }
        }
        return answer;
    }
};
class Solution3
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> answer;
        map<pair<int, int>, int> precal;
        for (int i = 0; i < queries.size(); i++)
        {
            int x = 0;
            if (precal.find({queries[i][0], queries[i][1]}) != precal.end())
            {
                answer.push_back(precal[{queries[i][0], queries[i][1]}]);
            }
            else
            {

                for (int j = queries[i][0]; j <= queries[i][1]; j++)
                {
                    x ^= arr[j];
                }
                precal[{queries[i][0], queries[i][1]}] = x;
                answer.push_back(x);
            }
        }
        return answer;
    }
};
class Solution4
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> answer;

        for (int i = 0; i < queries.size(); i++)
        {
            int x = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                x ^= arr[j];
            }
            answer.push_back(x);
        }
        return answer;
    }
};

int main()
{
    return 0;
}