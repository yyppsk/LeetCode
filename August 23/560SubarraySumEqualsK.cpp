#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{

    int count = 0;
    for (int start = 0; start < nums.size(); start++)
    {
        for (int end = start + 1; end <= nums.size(); end++)
        {
            int sum = 0;
            for (int i = start; i < end; i++)
                sum += nums[i];
            if (sum == k)
                count++;
        }
    }
    return count;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum(nums, k);
    return 0;
}