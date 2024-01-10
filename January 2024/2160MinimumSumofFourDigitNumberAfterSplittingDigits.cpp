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
    int minimumSum(int num)
    {
        vector<int> nums;
        nums.push_back(num % 10);
        num = num / 10;
        nums.push_back(num % 10);
        num = num / 10;
        nums.push_back(num % 10);
        num = num / 10;
        nums.push_back(num % 10);
        num = num / 10;
        int tens1, tens2;
        int ones1, ones2;
        sort(nums.begin(), nums.end());
        tens1 = nums[0];
        tens2 = nums[1];
        ones1 = nums[2];
        ones2 = nums[3];

        int result1 = (10 * tens1 + ones1) + (10 * tens2 + ones2);

        ones1 = nums[3];
        ones2 = nums[2];

        int result2 = (10 * tens1 + ones1) + (10 * tens2 + ones2);

        int final = min(result1, result2);
        return final;
    }
};
int main()
{
    return 0;
}