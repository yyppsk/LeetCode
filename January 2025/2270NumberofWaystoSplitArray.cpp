#include <bits/bits-stdc++.h>
using namespace std;
int waysToSplitArray(vector<int> &nums)
{

    long long totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalSum += nums[i];
    }
    long long forwardSum = 0, valid = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        forwardSum += nums[i];
        totalSum -= nums[i];

        if (forwardSum >= totalSum)
        {
            valid += 1;
        }
    }

    return valid;
}
int main()
{
    vector<int> arr = {10, 4, -8, 7};
    waysToSplitArray(arr);
    return 0;
}