#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void mergeWithSpace(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = 0, right = 0, index = 0;
    // take the extra space for the brute force idea
    vector<int> arr;
    while (left < m && right < n)
    {
        if (nums1[left] < nums2[right])
        {
            arr.push_back(nums1[left]);
            left++;
        }
        else
        {
            arr.push_back(nums2[right]);
            right++;
        }
    }
    // in any left over from either of the nums1 or nums2
    while (left < m)
    {
        arr.push_back(nums1[left]);
        left++;
    }
    while (right < n)
    {
        arr.push_back(nums2[right]);
        right++;
    }
    // refilling the OG array
    for (int i = 0; i < arr.size(); i++)
    {
        nums1[i] = arr[i];
    }
}
int main()
{
    return 0;
}