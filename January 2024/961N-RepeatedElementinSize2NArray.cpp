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
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size() / 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] == n)
            {
                return nums[i];
            }
        }
        return 0;
    }
};
int main()
{
    return 0;
}