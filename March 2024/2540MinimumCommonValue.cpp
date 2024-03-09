#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums2[j] > nums1[i])
                i++;
            else if (nums2[j] == nums1[i])
                return nums2[j];
            else
            {
                j++;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}