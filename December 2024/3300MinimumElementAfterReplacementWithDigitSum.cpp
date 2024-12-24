#include <bits/bits-stdc++.h>
using namespace std;
int minElement(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int currentDigitSum = 0;
        int number = nums[i];
        while (number > 0)
        {
            currentDigitSum += (number % 10);
            number /= 10;
        }
        nums[i] = currentDigitSum;
    }

    return *min_element(nums.begin(), nums.end());
}
int main()
{
    return 0;
}