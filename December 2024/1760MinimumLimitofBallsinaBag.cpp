#include <bits/bits-stdc++.h>
using namespace std;

bool check(vector<int> &nums, int maxOps, int mid)
{
    int total = 0;

    for (int &num : nums)
    {
        int operation = num / mid;

        if (num % mid == 0)
        {
            operation -= 1;
        }

        total += operation;
    }

    return total <= maxOps;
}

int minimumSize(vector<int> &nums, int maxOperations)
{
    int low = 1;
    int high = *max_element(begin(nums), end(nums));

    int result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(nums, maxOperations, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}
int main()
{
    return 0;
}