#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int specialArray(vector<int> &nums)
{
    int i = 1;
    int run = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (run < nums[i])
            run = nums[i];
    }
    while (run--)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {

            if (nums[j] >= i && count <= i)
            {
                count++;
            }
        }
        printf("For %d : Count %d\n", i, count);
        if (count == i)
        {
            return count;
        }
        i += 1;
    }
    return -1;
}
int binarysearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size();
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target)
            start = mid;
        else
            end = mid;
    }
}
int specialArraysol2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (auto x : nums)
    {
        cout << x << " ";
    }
    // loop for each number
    for (int i = 0; i < nums.size(); i++)
    {
        int index = binarysearch(nums, i);
        cout << "Indexes for " << i << " " << index << endl;
    }
    return 0;
    // Binary Search
}
int main()
{
    vector<int> arr = {0, 4, 3, 0, 4};
    cout << specialArraysol2(arr);
    return 0;
}