#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    vector<int> res;
    for (auto i : nums)
    {
        mp[i]++;
    }
    int factor = n / 3;
    for (auto i : mp)
    {
        if (i.second > factor)
            res.push_back(i.first);
        cout << i.first << ":" << i.second << endl;
    }
    return res;
}
int main()
{ 
    // Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
    vector<int> nums = {3, 2, 3};
    vector<int> res = majorityElement(nums);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}