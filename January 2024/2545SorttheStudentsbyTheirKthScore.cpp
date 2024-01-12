#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        int m = score.size();
        int n = score[0].size();

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++)
        {
            pq.push({score[i][k], i});
        }

        vector<vector<int>> res;
        while (!pq.empty())
        {
            int rowIndex = pq.top().second;
            pq.pop();
            res.push_back(score[rowIndex]);
        }
        return res;
    }
};
int main()
{
    return 0;
}