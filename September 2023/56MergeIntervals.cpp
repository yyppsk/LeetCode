#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0], end = intervals[i][1];
        /*
            Now when I will be at the 2nd interval checking,
            to ensure if the previously added interval is in the range of currently picked
            pair, I shall check if the ans is empty or not, if the ans array is not empty it
            ensures that that a interval was calculated previously and we have to check
            overlapping in it, like if current one is already in previous
        */
        if (!res.empty() && end <= res.back()[1])
        {
            continue; // skip current pair is it overlaps the previous interval already
        }
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
                end = max(end, intervals[j][1]);
            else
                break;
        }
        res.push_back({start, end});
    }

    return res;
}
int main()
{
    return 0;
}