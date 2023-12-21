#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        if (arr.size() == 1)
            return arr[0];
        if (arr[0] != arr[1])
            return arr[0];
        if (arr[arr.size() - 1] != arr[arr.size() - 2])
            return arr[arr.size() - 1];

        int low = 1, high = arr.size() - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            {
                return arr[mid];
            }
            else
            {
                if (mid % 2 == 1 && arr[mid] == arr[mid - 1] || mid % 2 == 0 && arr[mid] == arr[mid + 1])
                {
                    // left portion
                    low = mid + 1;
                }
                else
                {
                    // right half
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}