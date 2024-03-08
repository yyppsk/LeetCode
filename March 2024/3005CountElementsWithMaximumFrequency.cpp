#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;

            maxFreq = max(maxFreq, mp[nums[i]]);
        }

        int result = 0;
        for (auto &ele : mp)
        {
            if (ele.second >= maxFreq)
                result += ele.second;
        }
        return result;
    }
};
int main()
{
    return 0;
}