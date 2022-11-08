#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int minimumDifference(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = k - 1;
    int ans = INT_MAX;
    while (j < nums.size())
    {
        int currdiff = nums[j] - nums[i];
        ans = min(ans, currdiff);
        i++;
        j++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {9, 4, 1, 7};
    int k = 2;
    cout << minimumDifference(nums, k);
    return 0;
}