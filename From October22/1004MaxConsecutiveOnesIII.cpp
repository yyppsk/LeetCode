#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    int zero = 0;
    int window = 0;
    while (i < nums.size() && j < nums.size())
    {
        if (nums[j] == 0)
        {
            if (zero <= k)
            {
                zero++;
            }
        }
        if (zero > k)
        {
            while (zero > k)
            {
                if ((nums[i] == 0))
                    --zero;
                i++;
            }
        }
        window = max(j - i + 1, window);
        j++;
    }
    return window;
}
int main()
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << longestOnes(nums, k);
    return 0;
}
/*
else if (k >= zero)
            {
                window = max(j - i + 1, window);
                while (zero > k)
                {
                    if (nums[i] == 1)
                        i++;
                    else if (nums[i] == 0)
                    {
                        --zero;
                    }
                }
            }
*/