#include <bits/stdc++.h>
using namespace std;
int longestNiceSubarray(vector<int> nums)
{
    int commonAnd = nums[0];
    int size = 0;
    int maxi = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        commonAnd &= nums[i + 1];
        if (commonAnd != 0)
        {
            commonAnd = nums[i + 1];
            size = 0;
        }
        else
        {
            size++;
            maxi = max(maxi, size);
        }
    }
    return maxi;
}
int main()
{
    cout << longestNiceSubarray({1, 3, 8, 48, 10});
    return 0;
}