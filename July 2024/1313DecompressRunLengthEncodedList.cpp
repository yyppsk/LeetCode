#include <bits/bits-stdc++.h>
using namespace std;
vector<int> decompressRLElist(vector<int> nums)
{
    vector<int> decoded;
    for (int i = 0; (2 * i + 1) < nums.size(); i++)
    {
        int freq = nums[2 * i];
        int val = nums[2 * i + 1];
        while (freq--)
        {
            decoded.push_back(val);
        }
    }

    return decoded;
}
int main()
{
    decompressRLElist({1, 2, 3, 4});
    return 0;
}