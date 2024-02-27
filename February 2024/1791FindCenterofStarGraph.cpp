#include <bits/stdc++.h>
using namespace std;
class Solution2
{
public:
    int findCenter(vector<vector<int>> &edges)
    {

        unordered_map<int, int> freq;
        for (auto &edge : edges)
        {
            freq[edge[0]]++;
            freq[edge[1]]++;
            if (freq[edge[0]] >= edges.size())
                return edge[0];
            if (freq[edge[1]] >= edges.size())
                return edge[1];
        }
        return 0;
    }
};

class Solution
{
public:
    int findCenter(vector<vector<int>> &e)
    {

        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};
int main()
{
    return 0;
}