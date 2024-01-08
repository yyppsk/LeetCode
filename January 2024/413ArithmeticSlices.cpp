#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int numberOfArithmeticSlices1(vector<int> &nums)
{
    int n = nums.size();
    int currentSliceLength = 2;
    int totalArithmeticSlices = 0;

    for (int i = 2; i < n; ++i)
    {
        int prevDiff = nums[i - 1] - nums[i - 2];
        int currentDiff = nums[i] - nums[i - 1];

        if (prevDiff == currentDiff)
        {
            // The sequence continues, so increment the current slice length
            ++currentSliceLength;
        }
        else
        {
            // The sequence is broken, reset the current slice length to 2
            currentSliceLength = 2;
        }

        // If the current slice length is 3 or more, contribute to the count
        if (currentSliceLength >= 3)
        {
            totalArithmeticSlices += (currentSliceLength - 2);
        }
    }

    return totalArithmeticSlices;
}
// Bottom-Up Dynamic Programming Approach with Space Optimization:

int numberOfArithmeticSlicesBottomUp(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
    {
        return 0;
    }

    int count = 0;
    vector<int> dp(n, 0);

    for (int i = 2; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
            count += dp[i];
        }
    }

    return count;
}
int numberOfArithmeticSlices1(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            vector<int> temp;
            for (int k = i; k <= j; k++)
            {
                temp.push_back(nums[k]);
            }
            cout << endl;
            if (temp.size() >= 3)
            {

                int commonDiff = temp[1] - temp[0];
                bool isAth = true;
                for (int l = 1; l <= temp.size() - 1; l++)
                {
                    if (temp[l] - temp[l - 1] != commonDiff)
                    {
                        isAth = false;
                        break;
                    }
                }
                if (isAth)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
int numberOfArithmeticSlices(vector<int> &nums)
{
    if (nums.size() < 3)
        return 0;

    int cnt = 0, diff;

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        diff = nums[i + 1] - nums[i];

        for (int j = i + 2; j < nums.size(); ++j)
        {
            if (nums[j] - nums[j - 1] == diff)
                ++cnt;
            else
                break;
        }
    }
    return cnt;
}
int main()
{
    vector<int> num = {1, 2, 3, 8, 9, 10};
    cout << numberOfArithmeticSlices(num);
    return 0;
}