#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int findMiddleIndex(vector<int> &nums)
{
    int totalsum = 0;
    for (auto i : nums)
    {
        totalsum += i;
    }
    int leftsum = 0;
    // 1, 7, 3, 6, 5, 6
    for (int i = 0; i < nums.size(); i++)
    {
        int rightsum = totalsum - nums[i] - leftsum;
        cout << leftsum << " " << rightsum << endl;
        if (rightsum == leftsum)
        {
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}
/*Two pointer trial approach
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
*/
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
    cout << findMiddleIndex(nums);
    return 0;
}