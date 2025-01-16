#include <bits/bits-stdc++.h>
using namespace std;

// TLE
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s1, s2;

    for (int &ele : nums1)
    {
        s1.insert(ele);
    }

    for (int &ele : nums2)
    {
        s2.insert(ele);
    }

    int res = 0;

    for (auto &e : nums1)
    {
        for (auto &ele : nums2)
        {
            res ^= (ele ^ e);
        }
    }

    return res;
}

int main()
{
    return 0;
}