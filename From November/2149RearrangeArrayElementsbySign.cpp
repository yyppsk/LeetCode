#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> rearrangeArraybrute(vector<int> &nums)
{
    vector<int> result;
    int n = 0;
    vector<int> storage;
    for (int i : nums)
    {
        if (i > 0)
            storage.push_back(i);
        n += 1;
    }
    n = n / 2;
    for (int i : nums)
    {
        if (i < 0)
            storage.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        result.push_back(storage[i]);
        result.push_back(storage[n + i]);
    }
    return result;
}
vector<int> rearrangeArray(vector<int> &nums)
{   //Two pointers
    vector<int> res(nums.size(), 0);
    int pi = 0, ni = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            res[pi] = nums[i];
            pi += 2;
        }
        else
        {
            res[ni] = nums[i];
            ni += 2;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> res = rearrangeArray(nums);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}