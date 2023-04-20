#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
    /*
    0 <= i < j < k < arr.length
    |arr[i] - arr[j]| <= a
    |arr[j] - arr[k]| <= b
    |arr[i] - arr[k]| <= c
    */
    int cnt = 0;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            int k = j + 1;
            while (k <= arr.size() - 1)
            {
                if ((abs(arr[i] - arr[j]) <= a) && (abs(arr[j] - arr[k]) <= b) && (abs(arr[i] - arr[k]) <= c))
                    cnt++;
                k++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3};
    int a = 0, b = 0, c = 1;
    cout << countGoodTriplets(arr, a, b, c);
    return 0;
}