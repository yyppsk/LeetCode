#include <bits/bits-stdc++.h>
using namespace std;
int sumOfSquares(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (n % (i + 1) == 0)
        {
            sum += (nums[i] * nums[i]);
        }
    }
    return sum;
}
int main()
{
    return 0;
}