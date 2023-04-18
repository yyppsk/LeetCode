#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arithmeticTriplets(vector<int> &nums, int diff)
{
    // https://www.youtube.com/watch?v=5z971BdJ9-k
    //  exploit the property that the arr is increasing
    int cnt[201] = {}, res = 0;
    for (auto n : nums)
    {
        cout << n << " >= " << 2 * diff << endl;
        if (n >= 2 * diff)
            res += cnt[n - diff] && cnt[n - 2 * diff];
        cnt[n] = true;
    }
    for (int i = 0; i < 201; i++)
    {
        cout << cnt[i] << " ";
    }
    return res;
}
int main()
{
    vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    cout << arithmeticTriplets(nums, diff);
    return 0;
}