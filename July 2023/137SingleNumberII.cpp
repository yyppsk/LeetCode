#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int singleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int n = nums.size();
    int threeChecker = 1;
    while (i <= n - 3)
    {
        cout << "Checking " << nums[i] << " == " << nums[i + 1] << endl;
        if (nums[i] == nums[i + 1])
        {
            nums[i] = 173652;
            ++threeChecker;
            if (threeChecker == 3)
            {
                nums[i + 1] = 173652;
                threeChecker = 1;
            }
        }
        i++;
    }
    for (auto const &i : nums)
    {
        if (i != 173652)
            return i;
    }
    return 0;
}
int singleNumber2(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto const &i : nums)
    {
        mp[i]++;
    }
    for (auto const &i : mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 3, 2};
    cout << singleNumber(arr);
    return 0;
}