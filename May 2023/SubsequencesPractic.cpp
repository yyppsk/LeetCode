// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
void subsq(int idx, vector<int> ds, int arr[], int n)
{
    if (idx == n)
    {
        for (auto i : ds)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    // take the idx
    ds.push_back(arr[idx]);
    subsq(idx + 1, ds, arr, n);
    ds.pop_back();
    // not take the shit
    subsq(idx + 1, ds, arr, n);
}
int main()
{
    int arr[] = {3, 1, 2};
    vector<int> ds;
    int n = 3;
    subsq(0, ds, arr, n);
    return 0;
}