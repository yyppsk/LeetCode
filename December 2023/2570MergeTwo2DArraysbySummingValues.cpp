#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        int ptr1 = 0, ptr2 = 0;
        vector<vector<int>> answer;
        while (ptr1 < nums1.size() && ptr2 < nums2.size())
        {
            if (nums1[ptr1][0] > nums2[ptr2][0])
            {
                answer.push_back({nums2[ptr2][0], nums2[ptr2][1]});
                // answer.push_back({nums1[ptr1][0],nums1[ptr1][1]});
                ptr2++;
            }
            else if (nums1[ptr1][0] < nums2[ptr2][0])
            {
                answer.push_back({nums1[ptr1][0], nums1[ptr1][1]});
                // answer.push_back({nums2[ptr2][0],nums2[ptr2][1]});
                ptr1++;
            }
            else
            {
                answer.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++, ptr2++;
            }
        }
        while (ptr2 < nums2.size())
        {
            answer.push_back({nums2[ptr2][0], nums2[ptr2][1]});
            ptr2++;
        }
        while (ptr1 < nums1.size())
        {
            answer.push_back({nums1[ptr1][0], nums1[ptr1][1]});
            ptr1++;
        }
        return answer;
    }
};
int main()
{
    return 0;
}