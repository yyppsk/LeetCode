#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> result(nums.size(), 0);
    int smaller = 0, larger = 0, equal = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < pivot)
        {
            smaller++;
        }
        else if (nums[i] > pivot)
        {
            larger++;
        }
        else
        {
            equal++;
        }
    }

    int k = 0;

    // Arrange elements less than pivot
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < pivot)
        {
            result[k] = nums[i];
            k++;
        }
    }

    // Arrange elements equal to pivot
    for (int i = smaller; i < (smaller + equal); i++)
    {
        result[i] = pivot;
    }

    k = nums.size() - 1;

    // Arrange elements greater than pivot
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > pivot)
        {
            result[k] = nums[i];
            k--;
        }
    }

    for (auto ele : result)
    {
        cout << ele << " ";
    }

    return result;
}

int main()
{
    vector<int> nums1 = {9, 12, 5, 10, 14, 3, 10};
    vector<int> nums2 = {-3, 4, 3, 2};

    cout << "Example 1: ";
    pivotArray(nums1, 10);
    cout << endl;

    cout << "Example 2: ";
    pivotArray(nums2, 2);
    cout << endl;

    return 0;
}
