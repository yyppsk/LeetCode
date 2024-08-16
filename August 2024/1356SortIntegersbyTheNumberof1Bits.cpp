#include <bits/bits-stdc++.h>
using namespace std;
vector<int> sortByBits(vector<int> &arr)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        int copy = arr[i];
        int bitCount = 0;

        while (copy)
        {
            if (copy & 1)
                bitCount += 1;
            copy = copy >> 1;
        }
        pq.push({bitCount, arr[i]});
    }

    vector<int> result;
    while (!pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
int main()
{
    vector<int> arr = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    sortByBits(arr);
    return 0;
}