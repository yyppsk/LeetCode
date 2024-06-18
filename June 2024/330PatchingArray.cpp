#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int i = 0, count = 0;
        long maxSpanning = 0;

        while (maxSpanning < n)
        {

            if (i < nums.size() && nums[i] <= maxSpanning + 1)
            {
                maxSpanning += nums[i];
                i++;
            }
            else
            {
                maxSpanning += (maxSpanning + 1);
                count++;
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}