#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxProductDifference(vector<int> &nums)
{
    int a, b, c, d;

    sort(nums.begin(), nums.end());
    a = nums[nums.size() - 1];
    b = nums[nums.size() - 2];
    c = nums[1];
    d = nums[0];
    int diff = (a * b) - (c * d);
    return diff;
}
int main()
{
    vector<int> arr = {5, 6, 2, 7, 4};
    cout << maxProductDifference(arr);
    return 0;
}