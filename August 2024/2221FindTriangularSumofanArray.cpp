#include <bits/bits-stdc++.h>
using namespace std;

int triangularSum(vector<int> &nums)
{
    int n = nums.size();
    int size = n;
    int i = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            int a = nums[j];
            int b = nums[j + 1];
            nums[j] = (a + b) % 10;
        }
        size--;
    }

    return nums[0];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    triangularSum(nums);
    return 0;
}