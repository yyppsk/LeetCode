#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int binarysearch(vector<int> &arr, int k)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (arr[m] - m < k)
            l = m + 1;
        else
            r = m;
    }
    return l + k;
}
int findKthPositive(vector<int> &arr, int k)
{
    return binarysearch(arr, k);
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k) << endl;
    return 0;
}