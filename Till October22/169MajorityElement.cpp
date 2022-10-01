#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
int majorityElement(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]] = map[nums[i]] + 1;
    }
    bool iteration = false;
    int max = 0;
    int index;
    for (auto i : map)
    {
        if (iteration == false)
        {
            max = i.second;

            iteration = true;
        }
        cout << i.first << ":" << i.second << endl;
        if (i.second >= max)
        {
            max = i.second;
            index = i.first;
            cout << i.first << ":" << i.second << endl;
            printf("Max: %d\n", max);
        }
    }
    if (max >= (nums.size() / 2))
    {
        return index;
    }
    else
        return -1;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    cout << majorityElement(nums);
    return 0;
}