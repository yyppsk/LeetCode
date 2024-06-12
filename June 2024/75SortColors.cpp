#include <bits/bits-stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{

    int low = 0, high = nums.size() - 1, medium = 0;

    while (medium <= high)
    {
        if (nums[medium] == 1)
        {
            medium++;
        }
        else if (nums[medium] == 2)
        {
            swap(nums[high], nums[medium]);
            high--;
        }
        else
        {
            swap(nums[low], nums[medium]);
            low++, medium++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 2, 1, 1, 0, 1, 0, 0, 2};

    sortColors(arr);
    return 0;
}