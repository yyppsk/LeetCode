#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<pair<long long, long long>> pq;
        for (long long i = 0; i < gifts.size(); i++)
        {
            pq.push({gifts[i], i});
        }
        while (k)
        {
            long long root = sqrt(pq.top().first);
            gifts[pq.top().second] = (root);
            pair<long long, long long> backup = {root, pq.top().second};
            pq.pop();
            pq.push(backup);
            k--;
        }
        long long sum = 0;
        for (const int &el : gifts)
        {
            sum += el;
        }
        return sum;
    }
};
int main()
{
    return 0;
}