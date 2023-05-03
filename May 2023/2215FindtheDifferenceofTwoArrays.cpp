#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;
vector<int> getElementsOnlyInFirstList(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> onlyInNums1;

    // Store nums2 elements in an unordered set.
    unordered_set<int> existsInNums2;
    for (int num : nums2)
    {
        existsInNums2.insert(num);
    }

    // Iterate over each element in the list nums1.
    for (int num : nums1)
    {
        if (existsInNums2.find(num) == existsInNums2.end())
        {
            onlyInNums1.insert(num);
        }
    }

    // Convert to vector.
    return vector<int>(onlyInNums1.begin(), onlyInNums1.end());
}
vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    /*Naive
    vector<vector<int>> ans;
    set<int> grow;
    for (int i = 0; i < nums1.size(); i++)
    {
        bool check = 0;
        for (int j = 0; j < nums2.size(); j++)
        {
            cout << nums1[i] << " = " << nums2[j] << endl;
            if (nums1[i] == nums2[j])
            {
                check = 1;
            }
        }
        if (check != 1)
            grow.insert(nums1[i]);
    }
    std::vector<int> output(grow.begin(), grow.end());
    ans.push_back(output);
    grow.clear();
    for (int i = 0; i < nums2.size(); i++)
    {
        bool check = 0;
        for (int j = 0; j < nums1.size(); j++)
        {
            if (nums1[j] == nums2[i])
            {
                check = 1;
            }
        }
        if (check != 1)
            grow.insert(nums2[i]);
    }
    std::vector<int> output2(grow.begin(), grow.end());
    ans.push_back(output2);
    return ans;
    */
    /* O(N) and too much space
    vector<vector<int>> ans;
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    for (auto i : nums1)
    {
        mp1[i]++;
    }
    for (auto i : nums2)
    {
        mp2[i]++;
    }
    set<int> build;
    for (auto i : nums1)
    {
        bool check = 0;
        if (mp2[i] != 0)
        {
            check = 1;
        }
        if (check == 0)
            build.insert(i);
    }
    std::vector<int> output(build.begin(), build.end());
    ans.push_back(output);
    build.clear();
    for (auto i : nums2)
    {
        bool check = 0;
        cout << "find " << i << endl;
        if (mp1[i] != 0)
        {
            cout << "found " << i << endl;
            check = 1;
        }
        if (check == 0)
            build.insert(i);
    }
    std::vector<int> output2(build.begin(), build.end());
    ans.push_back(output2);
    return ans;
    */

    return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 3}, nums2 = {1, 1, 2, 2};
    vector<vector<int>> ans = findDifference(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}