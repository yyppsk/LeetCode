#include <bits/bits-stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        vector<int> answer;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for (auto it : mp)
        {
            if (it.second == 2)
            {
                answer.push_back(it.first);
            }
        }
        return answer;
    }
};
int main()
{
    return 0;
}