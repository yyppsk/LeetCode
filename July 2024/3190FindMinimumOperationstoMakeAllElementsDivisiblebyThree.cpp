#include <bits/bits-stdc++.h>
using namespace std;

int minimumOperations(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 3 == 1)
        {
            count++;
        }
        if (nums[i] % 3 == 2)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}