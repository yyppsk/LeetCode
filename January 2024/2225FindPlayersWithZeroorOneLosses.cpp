#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, pair<int, int>> results;
        for (int i = 0; i < matches.size(); i++)
        {
            results[matches[i][0]].first++;
            results[matches[i][1]].second++;
        }
        // cout << "P"
        //      << "-"
        //      << "W:"
        //      << "L\n";

        // for (auto ele : results) {
        //     cout << ele.first << "-" << ele.second.first << ":"
        //          << ele.second.second << "\n";
        // }

        vector<vector<int>> answer;
        vector<int> allWins;
        vector<int> exactOneLoss;
        for (auto ele : results)
        {

            if (ele.second.second == 0)
            {
                allWins.push_back(ele.first);
            }
            else if (ele.second.second == 1)
            {
                exactOneLoss.push_back(ele.first);
            }
        }
        return answer;
    }
};
int main()
{
    return 0;
}