#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    // i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​
    vector<pair<int, int>> res;
    int maxi = INT_MIN;
    for (int i = 0; i < nums1.size(); i++)
    {
        int start = i;
        int end = nums2.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if ((mid <= nums2[mid]) && (i <= mid))
            {
                res.push_back({mid, i});
            }
            if ((mid < nums2[mid]))
            {
                start = mid + 1;
            }
            if ((mid > nums2[mid]))
                end = mid - 1;
        }
    }
    for (auto i : res)
    {
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}
int main()
{
    vector<int> nums1 = {55, 30, 5, 4, 2}, nums2 = {100, 20, 10, 10, 5};
    maxDistance(nums1, nums2);
    return 0;
}