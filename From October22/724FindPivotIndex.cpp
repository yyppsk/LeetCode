#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findMiddleIndex(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    if (nums.size() == 2)
        return -1;
    int start = 0, end = nums.size();
    int leftsum = 0, rightsum = 0;
    cout << "L " << leftsum << " R " << rightsum << endl;
    while (start < end)
    {
        // printf("l %d + %d < r %d + %d\n", leftsum, nums[start], rightsum, nums[end - 1]);
        if ((leftsum + nums[start]) < (rightsum + nums[end - 1]))
        {
            leftsum += nums[start];

            start += 1;
        }
        else if ((leftsum + nums[start]) > (rightsum + nums[end - 1]))
        {
            rightsum += nums[end - 1];
            end -= 1;
        }
        else
        {
            leftsum += nums[start];
            rightsum += nums[end - 1];
            start += 1;
            end -= 1;
        }
        cout << "L " << leftsum << " R " << rightsum << endl;
    }
    // cout << start << endl;
    cout << "L " << leftsum << " R " << rightsum << endl;
    return end;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    cout << findMiddleIndex(nums);
    return 0;
}