#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int answer = 0;
        while (true)
        {
            for (int i = 0; i < tickets.size(); ++i)
            {
                if (tickets[i] == 0)
                    continue;
                tickets[i]--;
                ++answer;
                if (tickets[k] == 0)
                    return answer;
            }
        }
    }
};
class Solution2
{
public:
    int timeRequiredToBuy(vector<int> &nums, int k)
    {
        int res = 0;
        for (int i = 0; i <= k; i++)
        {
            res += min(nums[i], nums[k]);
        }
        for (int i = k + 1; i < nums.size(); i++)
        {
            res += min(nums[i], nums[k] - 1);
        }
        return res;
    }
};
int main()
{
    return 0;
}