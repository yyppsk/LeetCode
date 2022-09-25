#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int maxSubArray(vector<int> &nums, vector<int> &subarray)
{
    int max_sum = INT_MIN;
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    int i, j;
    for (i = 0; i <= n - 1; i++)
    {
        for (j = i; j <= n - 1; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                printf("%d + %d = %d \n", sum, nums[k], sum + nums[k]);
                sum = sum + nums[k];
            }
            if (sum > max_sum)
            {
                subarray.clear();
                max_sum = sum;
                subarray.push_back(i);
                subarray.push_back(j);
                cout << "Pushback " << i << " & " << j << endl;
            }
            else
            {
                cout << "Not Pushed\n";
            }
        }
    }
    return max_sum;
}

int maxSubArray2(vector<int> &nums, vector<int> &subarray)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr_sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            curr_sum += nums[j];
            if (curr_sum > max_sum)
            {
                subarray.clear();
                max_sum = curr_sum;
                subarray.push_back(i);
                subarray.push_back(j);
            }
        }
    }
    return max_sum;
}
int kdaneAlgo(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}
int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray;
    int lon = maxSubArray2(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nMax: " << kdaneAlgo(arr);
}