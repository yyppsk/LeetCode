#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> replaceElements(vector<int> &arr)
{
    int mx = -1;
    for (int i = arr.size() - 1; i >= 0; --i)
        mx = max(mx, exchange(arr[i], mx));
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return arr;
}
vector<int> replaceElements2(vector<int> &arr)
{
    int maxi = -1;
    for (int i = arr.size() - 1; i > -1; i--)
    {
        int newmax = max(maxi, arr[i]);
        arr[i] = maxi;
        maxi = newmax;
    }
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return arr;
}
int main()
{
    vector<int> arr{17, 18, 5, 4, 6, 1};
    replaceElements2(arr);
    return 0;
}