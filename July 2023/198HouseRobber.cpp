#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int stuffFinder(vector<int> &houses, int i)
{
    // base case
    if (i >= houses.size())
    {
        return 0;
    }
    int robAmt1 = houses[i] + stuffFinder(houses, i + 2);
    int robAmt2 = 0 + stuffFinder(houses, i + 1);
    return max(robAmt1, robAmt2);
}
void stuffFinder(vector<int> &houses, int &ans, int &curr, int idx)
{
    // base case
    if (idx >= houses.size())
    {
        ans = max(ans, curr);
        return;
    }
    // take the house
    curr = houses[idx] + curr;
    stuffFinder(houses, ans, curr, idx + 2);

    // leave the house
    curr = curr - houses[idx];
    stuffFinder(houses, ans, curr, idx + 1);
}
int rob(vector<int> &nums)
{
    int ans = INT_MIN;
    int curr = 0;
    stuffFinder(nums, ans, curr, 0);
    return ans;
}
int main()
{
    vector<int> rb = {1, 2, 3, 1};
    cout << rob(rb);
    return 0;
}