#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> stones)
{

    if (stones.size() == 1)
    {
        return stones[0];
    }
    priority_queue<int> pq(stones.begin(), stones.end());
    while (!pq.empty())
    {
        int elementY = pq.top();
        pq.pop();
        int elementX = pq.top();
        pq.pop();

        cout << elementX << ":" << elementY << "\n";
        if (elementY != elementX)
        {
            pq.push(elementY - elementX);
        }

        if (pq.size() == 0)
        {
            return 0;
        }
        else if (pq.size() == 1)
        {
            return pq.top();
        }
    }
    return 0;
}
int main()
{
    cout << lastStoneWeight({1});

    return 0;
}