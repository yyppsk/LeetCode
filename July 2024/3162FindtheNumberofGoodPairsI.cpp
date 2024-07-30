#include <bits/bits-stdc++.h>
using namespace std;
// A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int count = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] % (nums2[j] * k) == 0)
            {
                count += 1;
            }
        }
    }
    return count;
}

int main()
{
    return 0;
}