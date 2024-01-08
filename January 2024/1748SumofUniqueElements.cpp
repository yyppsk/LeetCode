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
    int sumOfUnique(vector<int> &nums)
    {
        int frequency[101] = {};
        for (int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }
        int sum = 0;
        for (int i = 0; i < 101; i++)
        {
            if (frequency[i] == 1)
            {
                sum += i;
            }
        }
        return sum;
    }
};
int main()
{
    return 0;
}