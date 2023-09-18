#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int subarraySum_Brute(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}
int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
        }
        if (sum == k)
            cnt++;
    }
    return 0;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    subarraySum(nums, 3);
    return 0;
}