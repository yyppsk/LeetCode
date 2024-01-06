#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]]++;
        }

        unordered_map<int, int> mp2;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp2[nums2[i]]++;
        }

        int countA = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mp2.find(nums1[i]) != mp2.end())
            {
                countA++;
            }
        }
        int countB = 0;

        for (int i = 0; i < nums2.size(); i++)
        {
            if (mp.find(nums2[i]) != mp.end())
            {
                countB++;
            }
        }
        return {countA, countB};
    }
};

int main()
{
    return 0;
}