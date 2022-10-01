#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arithmeticTriplets(vector<int> &nums, int diff)
{
    int counter = 0;
    int i = 0, j = 1, k = nums.size() - 1;
    while (j < nums.size())
    {
        if ((nums[j] - nums[i]) == diff)
        {
            if ((nums[k] - nums[j]) == diff)
            {
                counter += 1;
            }
            else
            {
                k -= 1;
            }
        }
        else
        {
            j += 1;
        }
    }
    return counter;
}
int main()
{
    vector<int> arr = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    cout << arithmeticTriplets(arr, diff) << endl;
    return 0;
}