#include <bits/bits-stdc++.h>
using namespace std;
int addedInteger(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    return nums1[0] - nums2[0];
}

int main()
{
    return 0;
}