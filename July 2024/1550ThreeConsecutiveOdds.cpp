#include <bits/bits-stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int> &arr)
{
    if (arr.size() <= 2)
    {
        return false;
    }

    int i = 0, j = 1, k = 2;
    for (; k < arr.size(); k++, j++, i++)
    {
        if (arr[i] % 2 == 1 && arr[j] % 2 == 1 && arr[k] % 2 == 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << threeConsecutiveOdds(arr);
    return 0;
}