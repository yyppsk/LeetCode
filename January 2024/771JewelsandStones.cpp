#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < stones.size(); i++)
        {
            mp[stones[i]]++;
        }
        int count = 0;
        for (int i = 0; i < jewels.size(); i++)
        {
            count += mp[jewels[i]];
        }
        return count;
    }
};
int main()
{
    return 0;
}