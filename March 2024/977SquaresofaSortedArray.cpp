#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> t(nums.size());
        int s = 0;
        int j = nums.size();
        int e = nums.size() - 1;
        while (j--)
        {

            if (abs(nums[e]) > abs(nums[s]))
                t[j] = nums[e] * nums[e--];
            else
                t[j] = nums[s] * nums[s++];
        }
        return t;
    }
};

int main()
{
    return 0;
}