#include <bits/bits-stdc++.h>
using namespace std;

int countSetBitS(int number)
{
    int setBits = 0;
    while (number > 0)
    {
        if ((number & 1) == 1)
        {
            setBits++;
        }
        number = number >> 1;
    }
    return setBits;
}

bool canSortArray(vector<int> &nums)
{
    bool sorted = true;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            sorted = false;
            break;
        }
    }

    if (sorted == true)
    {
        return true;
    }
    int n = nums.size();
    bool swapped = false;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1] && (countSetBitS(nums[j] == countSetBitS(nums[j + 1]))))
            {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {

            return false;
        }
    }

    return true;
}
int main()
{
    vector<int> n = {3, 16, 8, 4, 2};
    canSortArray(n);
    return 0;
}