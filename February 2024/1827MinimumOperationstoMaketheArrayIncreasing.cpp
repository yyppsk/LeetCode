#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
int minOperations(vector<int> nums)
{

    int steps = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            steps += (nums[i - 1] - nums[i]) + 1;
            int currentSteps = (nums[i - 1] - nums[i]) + 1;
            nums[i] += currentSteps;
        }
    }
    for (auto ele : nums)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << steps;
    return 0;
}
int main()
{
    minOperations({1, 1, 1});
    return 0;
}