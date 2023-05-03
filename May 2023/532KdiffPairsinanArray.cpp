#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;
int search(vector<int> &nums, int start, int xvalue)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == xvalue)
        {
            return mid;
        }
        else if (xvalue > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int findPairs(vector<int> &nums, int k)
{
    int c = 0;
    /*Naive

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            printf("%d - %d (%d)= %d\n", nums[i], nums[j], abs(nums[i] - nums[j]), k);
            if (abs(nums[i] - nums[j]) == k)
            {
                c++;
            }
        }
    }
    */
    /*Two Pointers & sort
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int low = 0, high = 1;
    while (high < nums.size())
    {
        if (nums[high] - nums[low] == k)
        {
            ans.insert({nums[low], nums[high]});
            ++high, ++low;
        }
        else if (nums[high] - nums[low] > k)
        {
            ++low;
        }
        else
        {
            ++high;
        }
        if (low == high)
            high++;
    }
    return ans.size();
    */

    /*Binary Search

    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (search(nums, i + 1, nums[i] + k != -1))
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();

    */
    // Unordered Map check if x+k exists in map or not
    unordered_map<int, int> a;
    for (int i : nums)
        a[i]++;
    int ans = 0;
    for (auto x : a)
    {
        if (k == 0)
        {
            if (x.second > 1)
                ans++;
        }
        else if (a.find(x.first + k) != a.end())
            ans++;
    }

    return ans;
}
int main()
{
    vector<int> n = {3, 1, 4, 1, 5};
    cout << findPairs(n, 2);
    return 0;
}