#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries)
    {
        vector<int> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int q = 0;
            for (int j = 0; j < points.size(); j++)
            {
                int x2 = queries[i][0];
                int x1 = points[j][0];
                int y1 = queries[i][1];
                int y2 = points[j][1];
                int d1 = pow(x2 - x1, 2);
                int d2 = pow(y2 - y1, 2);
                if (d1 + d2 <= pow(queries[i][2], 2))
                {
                    q++;
                }
            }
            result.push_back(q);
        }
        return result;
    }
};
int main()
{
    return 0;
}