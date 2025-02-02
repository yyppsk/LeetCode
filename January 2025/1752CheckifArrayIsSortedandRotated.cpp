#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return true;

        int inversionCount = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++inversionCount;
            }
        }

        if (nums[0] < nums[n - 1])
        {
            ++inversionCount;
        }

        return inversionCount <= 1;
    }
};
int main()
{
    return 0;
}