#include <bits/bits-stdc++.h>
using namespace std;
int duplicateNumbersXOR(vector<int> &nums)
{
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            res = res ^ nums[i];
            i++;
        }
    }
    return res;
}
int main()
{
    return 0;
}