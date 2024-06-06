#include <bits/bits-stdc++.h>
using namespace std;
bool isNStraightHand(vector<int> &hand, int groupSize)
{

    if (hand.size() % groupSize != 0)
    {
        return false;
    }

    unordered_map<int, int> count;

    for (int i = 0; i < hand.size(); i++)
    {
        count[hand[i]]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto &entry : count)
    {
        pq.push(entry.first);
    }

    while (!pq.empty())
    {
        int start = pq.top();
        pq.pop();

        int num = count[start];
        if (num > 0)
        {
            for (int i = 1; i < groupSize; i++)
            {
                if (count[start + i] < num)
                {
                    return false;
                }
                else
                {
                    count[start + i] -= num;
                }
            }
        }
    }

    return true;
}
int main()
{
    vector<int> hand = {1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3};
    int groupSize = 3;

    cout << isNStraightHand(hand, groupSize);

    return 0;
}