#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int noRows = mat.size(), noCols = mat[0].size();

    vector<pair<int, int>> SoldierCount;

    vector<int> res;

    for (int i = 0; i < noRows; i++)
    {
        int l = 0, r = noCols - 1;

        while (l <= r) // To find Last index of 1 in each Row ( Binary search )
        {
            int mid = l + (r - l) / 2;

            if (mat[i][mid] > 0)
                l = mid + 1;
            else
                r = mid - 1;
        }

        SoldierCount.push_back({l + 1, i}); // Add the no of 1's count and row index in SoldierCount
    }

    sort(SoldierCount.begin(), SoldierCount.end());

    for (auto &it : SoldierCount)
    {
        if (k == 0)
            break;

        res.push_back(it.second);

        k--;
    }

    return res;
}
int main()
{
    vector<vector<int>> mat =
        {{1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0},
         {1, 0, 0, 0, 0},
         {1, 1, 0, 0, 0},
         {1, 1, 1, 1, 1}};
    int k = 3;
    kWeakestRows(mat, k);
    return 0;
}