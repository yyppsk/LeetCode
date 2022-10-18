#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int MaxWindowLength(vector<int> arr, int k)
{
    int curr_sum = 0;
    int maxi = 0;
    int start = 0, end = arr.size();
    while (start < end)
    {
        curr_sum += arr[end];
        if (curr_sum < k) // expansion
            end++;
        if (curr_sum == k)
        {
            maxi = max(maxi, end - start + 1);
            end++;
        }
        else if (curr_sum > k)
        {
            while (curr_sum > k)
            {
                curr_sum -= arr[start];
                start += 1;
            }
            if (curr_sum == k)
                maxi = max(maxi, end - start + 1);
            end++;
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr = {5, 2, 1, 1, 1, 1, 3, 5, 2, 9};
    int sum = 7;
    cout << MaxWindowLength(arr, sum);
    return 0;
}