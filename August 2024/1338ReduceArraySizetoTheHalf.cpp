#include <bits/bits-stdc++.h>
using namespace std;
int minSetSize(vector<int> &arr)
{
    int originalSize = arr.size();
    unordered_map<int, int> frequency;

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        frequency[arr[i]]++;
    }

    for (auto &p : frequency)
    {
        pq.push({p.second, p.first});
    }

    int currentSize = originalSize;
    int countRemoval = 0;
    while (!pq.empty())
    {
        currentSize -= pq.top().first;
        pq.pop();
        countRemoval++;
        if (currentSize <= (originalSize / 2))
        {
            return countRemoval;
        }
    }

    return countRemoval;
}
int main()
{
    vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    minSetSize(arr);
    return 0;
}