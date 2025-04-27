#include <bits/bits-stdc++.h>
using namespace std;
int countSubarrays(vector<int> &nums)
{
    int count = 0;
    for (int i = 2; i < nums.size(); i++)
    {
        if ((nums[i - 2] + nums[i]) == (nums[i - 1] / 2))
        {
            count += 1;
        }
    }

    return count;
}
int main()
{
    return 0;
}