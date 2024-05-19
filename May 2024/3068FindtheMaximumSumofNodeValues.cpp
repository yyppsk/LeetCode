#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k,
                              vector<vector<int>> &edges)
    {
        long long sum = 0;
        int lossOccured = INT_MAX;
        int count = 0;
        for (long long num : nums)
        {

            if ((num ^ k) > num)
            {
                sum += (num ^ k);
                count++;
            }
            else
            {
                sum += num;
            }

            lossOccured = min((long long)lossOccured, abs(num - (num ^ k)));
        }
        if (count % 2 == 0)
        {
            return sum;
        }
        return sum - lossOccured;
    }
};
int main()
{
    return 0;
}