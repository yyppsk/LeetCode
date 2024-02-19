#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i += 2)
        {
            sum += min(nums[i], nums[i + 1]);
        }
        return sum;
    }
};
int main()
{
    return 0;
}