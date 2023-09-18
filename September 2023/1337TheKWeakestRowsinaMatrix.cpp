#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

// nlogn + O(n2) + O(n)
vector<int> kWeakestRows_sorting(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> weakestRows;
    for (int i = 0; i < mat.size(); i++)
    {
        int counter = 0;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j])
            {
                counter++;
            }
        }
        weakestRows.push_back({counter, i});
    }
    // for(auto ele : weakestRows){
    //     cout<<ele.first<<":"<<ele.second<<endl;
    // }
    sort(weakestRows.begin(), weakestRows.end());
    // for(auto ele : weakestRows){
    //     cout<<ele.first<<":"<<ele.second<<endl;
    // }
    vector<int> result;
    for (auto i : weakestRows)
    {
        if (k-- == 0)
            break;
        result.push_back(i.second);
    }
    return result;
}

// O(nlogn) + O(n) SPACE  O(n)
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{

    set<pair<int, int>> weakestRows;
    for (int i = 0; i < mat.size(); i++)
    {
        int counter = 0;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j])
            {
                counter++;
            }
        }
        weakestRows.insert({counter, i});
    }
    vector<int> result;
    for (auto i : weakestRows)
    {
        if (k-- == 0)
            break;
        result.push_back(i.second);
    }
    return result;
}
int main()
{
    vector<vector<int>> vec = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    kWeakestRows(vec, 3);
    return 0;
}