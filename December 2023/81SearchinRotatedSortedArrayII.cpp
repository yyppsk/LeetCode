#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &arr, int key)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return true;

            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }
            // right sorted
            if (arr[mid] >= arr[low])
            {
                if (arr[low] <= key && key <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                // left sorted
                if (arr[mid] <= key && key <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}