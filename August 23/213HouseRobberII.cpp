#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int maxStuff(vector<int> &nums)
    {
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2; // i-2 wali condition
            int notpick = 0 + prev;
            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        vector<int> t1, t2;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
                t1.push_back(nums[i]);
            if (i != nums.size() - 1)
                t2.push_back(nums[i]);
        }
        return max(maxStuff(t1), maxStuff(t2));
    }
};
int main()
{
    return 0;
}