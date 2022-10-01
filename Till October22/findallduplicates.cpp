#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        printf("For i = %d:\n", i);
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
        {
            cout << "\nFound Index :" << index << endl;
            res.push_back(abs(index + 1));
        }
        nums[index] = -nums[index];
    }

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return res;
}
int main()
{
    vector<int> aray = {4, 8, 7, 6, 1, 5, 2, 1, 3};
    aray = findDuplicates(aray);
    for (auto i : aray)
    {
        cout << i << " ";
    }
    return 0;
}

// mark the element as negative, which indicates that this index was "visited" already. brilliant!'
// The basic idea is to treat array values as indices.
// Why multiply by -1? Because we still want to somehow retrieve the original value.
// Here is my shorter solution:
// use opposite so that we can store the original value, wow, so smart.
// https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/92387/Java-Simple-Solution/1107305