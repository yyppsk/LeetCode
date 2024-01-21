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
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int setBits = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int number = i;
            int counter = 0;
            int digit;
            while (number)
            {
                counter += number & 1;
                number >>= 1;
            }
            if (counter == k)
            {
                setBits += nums[i];
            }
        }
        return setBits;
    }
};
int main()
{
    return 0;
}