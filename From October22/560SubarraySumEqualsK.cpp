#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int subarraySum2(vector<int> &nums, int k)
{
    int maximumSubArraySum = INT_MIN;
    /*
       We will use these outer 2 for loops to investigate all
       windows of the array.

       We plant at each 'left' value and explore every
       'right' value from that 'left' planting.

       These are our bounds for the window we will investigate.
     */
    for (int left = 0; left < nums.size(); left++)
    {
        for (int right = left; right < nums.size(); right++)
        {
            int windowSum = 0;
            for (int k = left; k < right; k++)
            {
                windowSum += nums[k];
                cout << nums[k] << " ";
            }
            cout << "\n";
            maximumSubArraySum = max(maximumSubArraySum, windowSum);
        }
    }
    return 0;
}
void subarraySum(vector<int> &nums, int k)
{
    // Initialise the variable with minimum integer value
    int maximumSubArraySum = INT_MIN;
    for (int left = 0; left < nums.size(); left++)
    {
        int runningwindowsum = 0;

        // Right will be the ending index of subarray
        for (int right = left; right < nums.size(); right++)
        {
            cout << nums[right] << " ";
            // Add the current element to previous computed value
            // To get the subarray sum
            runningwindowsum += nums[right];

            // Does this window beat the best sum we have seen so far?
            maximumSubArraySum = max(maximumSubArraySum, runningwindowsum);
        }
        cout << runningwindowsum << " ";
        cout << endl;
    }
}
void subarraySum3(vector<int> &nums, int k)
{
    // Initialise the variable with minimum integer value
    int maximumSubArraySum = INT_MIN;
    for (int left = 0; left < nums.size(); left++)
    {
        int runningwindowsum = 0;

        // Right will be the ending index of subarray
        for (int right = left; right < nums.size(); right++)
        {
            cout << nums[right] << " ";
            // Add the current element to previous computed value
            // To get the subarray sum
            runningwindowsum += nums[right];

            // Does this window beat the best sum we have seen so far?
            maximumSubArraySum = max(maximumSubArraySum, runningwindowsum);
        }
        cout << runningwindowsum << " ";
        cout << endl;
    }
}
int main()
{
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr = {1, 2, 3, 4};
    subarraySum(arr, 2);
    return 0;
}