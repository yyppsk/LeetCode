#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequencyMap;
        for (int i = 0; i < nums.size(); i++)
        {
            frequencyMap[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto ele : frequencyMap)
        {
            v.push_back({ele.second, ele.first});
        }
        sort(v.begin(), v.end());
        int idx = 0;
        while (k--)
        {
            if (v[idx].first == 0)
            {
                idx++;
            }
            v[idx].first--;
        }
        int count = 0;
        for (auto ele : v)
        {
            if (ele.first >= 1)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}