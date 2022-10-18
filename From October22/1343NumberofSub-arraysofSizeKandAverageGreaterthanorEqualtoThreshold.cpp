#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    // HIT THE FIRST WINDOW of size-k
    int count = 0;
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
    {
        curr_sum += arr[i];
    }
    int avg = curr_sum / k;
    if (avg >= threshold)
        count += 1;
    int start = 0, end = k;
    while (end < arr.size())
    {
        curr_sum += arr[end] - arr[start];
        avg = curr_sum / k;
        if (avg >= threshold)
        {
            count += 1;
        }
        start += 1;
        end += 1;
    }
    return count;
}
int main()
{
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3, threshold = 4;
    cout << numOfSubarrays(arr, k, threshold);
    return 0;
}