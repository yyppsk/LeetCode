#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int size = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());
    cout << maxi << endl;
    vector<int> arr(nums.size() + 1, -1);
    for (int i = 0; i < nums.size(); i++)
    {
        // printf("Putting 1 in index %d\n", nums[i]);
        arr[nums[i]] = 1;
    }
    vector<int> ans;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    /*Given an array nums of n integers where nums[i] is in the range [1, n],
    return an array of all the integers in the range [1, n] that do not appear in nums.
Input: nums = [4,3,2,7,8,2,3,1]
    */
    vector<int> nums = {1, 1};
    findDisappearedNumbers(nums);
    return 0;
}