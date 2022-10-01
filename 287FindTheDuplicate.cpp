#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
void solve()
{
}
int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    unordered_set<int> set1(nums.begin(), nums.end());
    int sumofset = 0, sumofnum = 0;
    for (auto i : set1)
    {
        sumofset += i;
    }
    cout << sumofset << endl;
    for (int i : nums)
        sumofnum += i;
    cout << sumofnum - sumofset << endl;
    return 0;
}