#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int CountSub(int idx, int arr[], int k, int sum, int n)
{
    //only if the array has all the positives
    if (sum > k)
        return 0;
    if (idx == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum += arr[idx];
    int left = CountSub(idx + 1, arr, k, sum, n);
    sum -= arr[idx];
    int right = CountSub(idx + 1, arr, k, sum, n);
    return left + right;
}
int main()
{
    int arr[] = {1, 2, 1};
    int k = 2;
    cout << CountSub(0, arr, k, 0, 3);
    return 0;
}