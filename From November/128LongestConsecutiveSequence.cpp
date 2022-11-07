#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    set<int> hashset;
    for (int num : nums)
    {
        hashset.insert(num);
    }
    int longest = 0;
    for (int num : nums)
    {
        if (!hashset.count(num - 1))
        {
            int currentnumber = num;
            int currlong = 1;
            while (hashset.count(currentnumber + 1))
            {
                currentnumber += 1;
                currlong += 1;
            }
            longest = max(longest, currlong);
        }
    }
    return longest;
}
int main()
{
    // Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
    return 0;
}