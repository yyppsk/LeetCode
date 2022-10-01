#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
        map[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
    {
        int val = target - nums[i];

        if (map[val])
        {
            result.push_back(map[nums[i]]);
            result.push_back(map[val]);
            break;
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {3, 3};
    cout<<sum
    return 0;
}