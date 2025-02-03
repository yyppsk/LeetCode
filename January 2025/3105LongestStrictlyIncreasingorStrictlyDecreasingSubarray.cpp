#include <bits/bits-stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    int inc = 0;
    int len = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            len += 1;
        }
        else
        {
            inc = max(inc, len);
            len = 1;
        }
    }
    inc = max(inc, len);

    int dec = 0;
    len = 1;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            len += 1;
        }
        else
        {
            dec = max(dec, len);
            len = 1;
        }
    }
    dec = max(dec, len);

    cout << dec;
    return max(inc, dec);
}

int longestMonotonicSubarray(vector<int> &nums)
{

    int incLength = 1, decLength = 1;
    int maxLength = 1;

    for (int pos = 0; pos < nums.size() - 1; pos++)
    {
        if (nums[pos + 1] > nums[pos])
        {

            incLength++;
            decLength = 1;
        }
        else if (nums[pos + 1] < nums[pos])
        {

            decLength++;
            incLength = 1; // Reset increasing sequence
        }
        else
        {
            // If elements are equal, reset both sequences
            incLength = 1;
            decLength = 1;
        }

        // Update max length considering both sequences
        maxLength = max(maxLength, max(incLength, decLength));
    }
    return maxLength;
}
int main()
{
    vector<int> nums = {3, 2, 1};
    longestMonotonicSubarray(nums);
    return 0;
}