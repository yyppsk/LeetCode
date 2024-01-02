#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        int MaxOccuringNumber = -1;
        int MaxFrequency = -1;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++; // calculating frequency
            if (MaxFrequency < freq[nums[i]])
            {
                MaxOccuringNumber = nums[i];
                MaxFrequency = freq[nums[i]];

                // checking highest frequency in the map
            }
        }

        for (int i = 0; i <= MaxFrequency; i++)
        {
            vector<int> tmp;
            for (auto &ele : freq)
            {
                if (ele.second > 0)
                {
                    tmp.push_back(ele.first);
                    ele.second--;
                }
            }
            if (i != MaxFrequency)
                res.push_back(tmp);
        }
        return res;
    }
};
int main()
{
    return 0;
}