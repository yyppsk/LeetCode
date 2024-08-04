#include <bits/bits-stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int rangeSum(vector<int> &nums, int n, int left, int right)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> prefix(nums.size(), 0);
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    vector<int> sortedOrder;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int currentSum = 0;
            if (i == 0)
            {
                currentSum = prefix[j];
            }
            else
            {
                currentSum = prefix[j] - prefix[i - 1];
            }
            sortedOrder.push_back(currentSum);
        }
    }

    sort(sortedOrder.begin(), sortedOrder.end());
    int sum = 0;
    for (int i = left - 1; i <= right - 1; i++)
    {
        sum = (sum + sortedOrder[i]) % MOD;
    }

    return sum;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = 4, left = 1, right = 5;
    rangeSum(nums, n, left, right);
    return 0;
}