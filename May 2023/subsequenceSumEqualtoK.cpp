#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void subsqsum(int idx, int arr[], vector<int> &ds, int s, int sum, int n)
{
    if (idx == n)
    {
        if (s == sum)
            for (auto i : ds)

                cout << i << " ";
        cout << endl;

        return;
    }
    ds.push_back(arr[idx]);
    s += arr[idx];
    subsqsum(idx + 1, arr, ds, s, sum, n);
    s -= arr[idx];
    ds.pop_back();
    subsqsum(idx + 1, arr, ds, s, sum, n);
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