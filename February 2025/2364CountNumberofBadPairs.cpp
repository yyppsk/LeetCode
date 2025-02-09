#include <bits/bits-stdc++.h>
using namespace std;
long long countBadPairs(vector<int> &nums)
{
    long long pairs = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j - i != nums[j] - nums[i])
            {
                pairs += 1;
            }
        }
    }
    return pairs;
}
long long countBadPairs(vector<int> &nums)
{
    long long badPairs = 0;
    unordered_map<int, int> diffCount;

    for (int pos = 0; pos < nums.size(); pos++)
    {
        int diff = pos - nums[pos];

        int goodPairsCount = diffCount[diff];

        badPairs += pos - goodPairsCount;

        diffCount[diff] = goodPairsCount + 1;
    }

    return badPairs;
}
int main()
{
    vector<int> nums = {4, 1, 3, 3};
    countBadPairs(nums);
    return 0;
}