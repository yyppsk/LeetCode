#include <bits/bits-stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int> &arr)
{
    int size = arr.size();
    vector<int> largestSoFar(size);
    vector<int> smallestWithCurrent(size);

    largestSoFar[0] = arr[0];
    smallestWithCurrent[size - 1] = arr[size - 1];

    for (int i = 1; i < size; i++)
    {
        largestSoFar[i] = max(arr[i], largestSoFar[i - 1]);
    }

    for (int i = size - 2; i >= 0; i--)
    {
        smallestWithCurrent[i] = min(arr[i], smallestWithCurrent[i + 1]);
    }

    int chunk = 0;

    for (int i = 0; i < size; i++)
    {
        int maxBeforeCurrent = i > 0 ? largestSoFar[i - 1] : -1;
        int minAfterCurrent = smallestWithCurrent[i];
        if (maxBeforeCurrent < minAfterCurrent)
        {
            chunk += 1;
        }
    }

    return chunk;
}
int main()
{
    return 0;
}