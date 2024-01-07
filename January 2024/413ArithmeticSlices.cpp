#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// Recursive Approach
int countSlicesRecursive(vector<int> &nums, int end)
{
    if (end < 2)
    {
        return 0;
    }

    int count = 0;
    for (int start = 0; start < end - 1; start++)
    {
        if (nums[end] - nums[end - 1] == nums[end - 1] - nums[start])
        {
            count += 1 + countSlicesRecursive(nums, start);
        }
    }

    return count;
}

int numberOfArithmeticSlicesRecursive(vector<int> &nums)
{
    int n = nums.size();
    return countSlicesRecursive(nums, n - 1);
}
//      Top -  Down Dynamic Programming Approach
int countSlicesTopDown(vector<int> &nums, int end, vector<int> &dp)
{
    if (end < 2)
    {
        return 0;
    }

    if (dp[end] != -1)
    {
        return dp[end];
    }

    int count = 0;
    for (int start = 0; start < end - 1; start++)
    {
        if (nums[end] - nums[end - 1] == nums[end - 1] - nums[start])
        {
            count += 1 + countSlicesTopDown(nums, start, dp);
        }
    }

    dp[end] = count;
    return count;
}

int numberOfArithmeticSlicesTopDown(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return countSlicesTopDown(nums, n - 1, dp);
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