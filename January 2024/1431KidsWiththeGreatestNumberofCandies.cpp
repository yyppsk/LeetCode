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
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxcandy = *max_element(candies.begin(), candies.end());
        vector<bool> result(candies.size(), false);
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= maxcandy)
            {
                result[i] = 1;
            }
            else
            {
                result[i] = 0;
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}