#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int arithmeticTriplets(vector<int> &nums, int diff)
{
    int c = 0;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = 1; i < nums.size() - 1; i++)
        {
            for (int k = 2; i < nums.size(); i++)
            {
                if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff))
                {
                    c++;
                }
            }
        }
    }
    return c;
}
int main()
{
    vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    cout << arithmeticTriplets(nums, diff);
    return 0;
}