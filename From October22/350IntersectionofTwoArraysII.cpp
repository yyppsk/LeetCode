#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
int bs(vector<int> arr, int target)
{

    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return -1;
}
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return intersect(nums2, nums1);
    vector<int> result;
    sort(nums2.begin(), nums2.end());
    for (int i = 0; i < nums1.size(); i++)
    {
        int index = bs(nums2, nums1[i]);
        if (index >= 0)
        {
            result.push_back(nums1[i]);
            nums2.erase(nums2.begin() + index); // delete the pushed element
        }
    }
    return result;
}
int main()
{
    vector<int> nums1 = {9, 4, 9, 8, 4}, nums2 = {4, 9, 5};
    intersect(nums1, nums2);
    return 0;
}