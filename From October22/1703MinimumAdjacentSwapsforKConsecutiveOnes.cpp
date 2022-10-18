#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int minMoves(vector<int> &nums, int k)
{
    vector<int> positionarray;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            positionarray.push_back(i);
    }
    vector<int> prefixsum(positionarray.size());
    int sum = 0;
    for (int i = 0; i < positionarray.size(); i++)
    {
        sum += positionarray[i];
        prefixsum[i] = prefixsum[i] + (i == 0 ? 0 : prefixsum[i - 1]);
    }
    for (auto i : prefixsum)
    {
        cout << i << " ";
    }
    /*
    int start = 0;
    int end = k - 1;
    int mid;
    int totalmoves;
    int rsum = 0, lsum = 0;
    int rad;
    int same = 0;
    int ans = 0;
    while (end < nums.size())
    {
        if (k % 2 == 1)
        {
            mid = start + k / 2;
            rsum = prefixsum[start] - prefixsum[mid];
            lsum = (mid == 0 ? 0 : prefixsum[mid - 1]) - (end == 0 ? 0 : prefixsum[end - 1]);
            totalmoves = rsum - lsum;
            rad = mid - end;
            same = rad * (rad + 1);
            ans = min(ans, totalmoves - same);
        }
        end++;
        start++;
    }

    return ans;
    */
    return 0;
}
int main()
{
    vector<int> nums = {1, 0, 0, 1, 0, 1};
    int k = 2;
    cout << minMoves(nums, k);
    return 0;
}