#include <bits/bits-stdc++.h>
using namespace std;
long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    unordered_map<int, int> factorsInNums1;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 1; j < sqrt(nums1[i]); j++)
        {
            if (nums1[i] % j == 0)
            {
                factorsInNums1[j]++;
                if ((nums1[i] / j) != nums1[i])
                {
                    factorsInNums1[nums1[i] / j]++;
                }
            }
        }
    }

    long long int result = 0;

    for (int i = 0; i < nums2.size(); i++)
    {
        int number = nums2[i] * k;
        if (factorsInNums1[number] > 0)
        {
            result += factorsInNums1[number];
        }
    }

    return result;
}
int main()
{
    return 0;
}