#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
            // printf("Compare %d with %d\n", nums[i], nums[j]);
        }
        ans.push_back(count);
        // cout << "Count: " << count << endl;
        // cout << endl;
    }
    return ans;
}
int main()
{
    vector<int> arr = {8, 1, 2, 2, 3};
    smallerNumbersThanCurrent(arr);
    return 0;
}