#include <bits/bits-stdc++.h>
using namespace std;

// TLE solution
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

// Optimal
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, long> freq;

    int lengthNums1 = nums1.size();
    int lengthNums2 = nums2.size();

    for (int &ele : nums1)
    {
        freq[ele] += lengthNums2;
    }

    for (int &ele : nums2)
    {
        freq[ele] += lengthNums1;
    }

    int res = 0;

    for (auto &e : freq)
    {
        if (e.second % 2 == 1)
        {
            res ^= e.first;
        }
    }
    return res;
}

int main()
{
    return 0;
}