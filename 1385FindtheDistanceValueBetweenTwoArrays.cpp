#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool bs(vector<int> &arr2, int from, int to)
{
    /*
    The math rule is: |x| <= a equals to -a <= x <= a. Check it and you'll see that it's correct. So:

    the initial inequality is: |arr1[i] - arr2[j]| <= d
    according to the rule: -d <= arr1[i] - arr2[j] <= d
    then move arr1[i] to the other sides: -d - arr1[i] <= -arr2[j] <= d - arr1[i]
    then multiply it by -1 and flip inequality signs: d + arr1[i] >= arr2[j] >= arr1[i] - d
    that's the same as: arr1[i] - d <= arr2[j] <= arr1[i] + d
    */
    int start = 0;
    int end = arr2.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr2[mid] >= from && arr2[mid] <= to)
        {
            return false;
        }
        else if (arr2[mid] < from)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return true;
}
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int count = 0;
    sort(arr2.begin(), arr2.end());
    for (auto i : arr1)
    {
        if (bs(arr2, i - d, i + d))
            count++;
    }
    return count;
}
int main()
{
    vector<int> arr1 = {4, 5, 8}, arr2 = {10, 9, 1, 8};
    int d = 2;
    cout << findTheDistanceValue(arr1, arr2, d);
    return 0;
}