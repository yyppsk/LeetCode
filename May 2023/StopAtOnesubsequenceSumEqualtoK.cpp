#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool subsqsum(int idx, int arr[], vector<int> &ds, int s, int sum, int n)
{
    if (idx == n)
    {
        // satisfied so stop
        if (s == sum)
        {
            for (auto i : ds)
                cout << i << " ";
            cout << endl;
            return true;
        }
        else
            return false;
    }
    ds.push_back(arr[idx]);
    s += arr[idx];
    if (subsqsum(idx + 1, arr, ds, s, sum, n) == true)
        return true;
    s -= arr[idx];
    ds.pop_back();
    if (subsqsum(idx + 1, arr, ds, s, sum, n) == true)
        return true;
    return false;
}
int main()
{
    int arr[] = {1, 2, 1};
    vector<int> ds;
    int n = 3;
    int sum = 2;
    int s = 0;
    subsqsum(0, arr, ds, s, sum, n);
    return 0;
}