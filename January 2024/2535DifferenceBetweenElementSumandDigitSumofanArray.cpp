#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int elementSum = accumulate(nums.begin(), nums.end(), elementSum);
        int digitSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int number = nums[i];
            while (number > 0)
            {
                int digit = number % 10;
                number = number / 10;
                digitSum += digit;
            }
        }
        return abs(elementSum - digitSum);
    }
};
int main()
{
    return 0;
}