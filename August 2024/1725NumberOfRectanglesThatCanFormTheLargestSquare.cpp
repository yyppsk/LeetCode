#include <bits/bits-stdc++.h>
using namespace std;

int countGoodRectangles(vector<vector<int>> &rectangles)
{
    map<int, int> mp;
    for (auto x : rectangles)
        mp[min(x[0], x[1])]++;
    return mp.rbegin()->second;
}
int main()
{
    return 0;
}