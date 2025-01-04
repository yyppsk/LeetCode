#include <bits/bits-stdc++.h>
using namespace std;
vector<long long> findPrefixScore(vector<int> &nums)
{
    vector<long long> res;
    long long currMax = -1;
    long long sum = 0;
    long long score = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        long long score = 0;

        currMax = max((long long)nums[i], currMax);
        sum += currMax + nums[i];
        score += sum;

        res.emplace_back(score);
    }

    return res;
}
int main()
{
    vector<int> arr = {2, 3, 7, 5, 10};
    findPrefixScore(arr);
    return 0;
}