#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void sortColors(vector<int> &arr)
{
    int high = arr.size() - 1;
    int low = 0, mid = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low += 1;
            mid += 1;
        }
        else if (arr[mid] == 1)
        {
            mid += 1;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high -= 1;
        }
    }
    for (auto i : arr)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    return 0;
}