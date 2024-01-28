#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
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
    int subarraySumNsquare(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    }
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;

        long long sum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end())
            {
                result += mp[sum - k];
            }
            mp[sum]++;
        }
        return result;
    }
};
int main()
{
    return 0;
}