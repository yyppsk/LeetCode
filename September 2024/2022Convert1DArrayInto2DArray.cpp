#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (original.size() != m * n)
        {
            return {};
        }
        vector<vector<int>> result;
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(original[k]);
                k++;
            }

            result.push_back(temp);
        }

        return result;
    }
};
int main()
{
    return 0;
}