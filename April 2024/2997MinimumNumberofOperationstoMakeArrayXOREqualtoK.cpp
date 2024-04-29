#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    int xor_res = reduce(begin(nums), end(nums), k, bit_xor<>());
    return __builtin_popcount(xor_res);
}
int main()
{
    vector<int> nums = {2, 1, 3, 4};
    cout << minOperations(nums, 1);
    return 0;
}