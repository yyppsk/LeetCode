#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> findClosestElements2(vector<int> &arr, int k, int x)
{
}
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int low = 0, high = arr.size() - 1;
    while (high - low >= k)
    {
        if (abs(x - arr[low]) > abs(x - arr[high]))
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    vector<int> ans;
    for (int i = low; i <= high; i++)
    {
        ans.push_back(arr[i]);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return ans;
}
int main()
{
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4, x = 35;
    findClosestElements(arr, k, x);
    return 0;
}