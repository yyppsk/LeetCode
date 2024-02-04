#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int n;
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        n = arr.size();
        return solve(0, arr, k);
    }

private:
    int solve(int idx, vector<int> &arr, int k)
    {
        if (idx >= n)
            return 0;

        int result = 0;
        int maxcurrent = -1;
        for (int j = idx; j < n && j - idx + 1 <= k; j++)
        {
            maxcurrent = max(maxcurrent, arr[j]);

            result = max((j - idx + 1) * maxcurrent + solve(j + 1, arr, k), result);
        }
        return result;
    }
};
int maxSumAfterPartitioningHelper(vector<int> &arr, int k, int idx)
{
    if (idx == arr.size())
    {
        return 0;
    }

    int maxSum = 0;
    int maxElement = 0;
    for (int i = idx; i < min(idx + k, (int)arr.size()); i++)
    {
        maxElement = max(maxElement, arr[i]);
        int currSum = maxElement * (i - idx + 1) + maxSumAfterPartitioningHelper(arr, k, i + 1);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    return maxSumAfterPartitioningHelper(arr, k, 0);
}

int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout << maxSumAfterPartitioning(arr, 3) << endl;
    return 0;
}
