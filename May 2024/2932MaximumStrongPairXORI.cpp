#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int answer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                {
                    answer = max(answer, nums[i] ^ nums[j]);
                }
            }
        }
        return answer;
    }
};
int main()
{
    return 0;
}