#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool checkIfExist(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int target = arr[i] * 2;
        cout << "Target: " << arr[i] << " " << target << endl;
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target)
                return true;
            if (target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {-2, 0, 10, -19, 4, 6, -8};
    cout << checkIfExist(arr);
    return 0;
}