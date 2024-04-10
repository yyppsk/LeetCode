#include <bits/stdc++.h>
using namespace std;
vector<int> deckRevealedIncreasing(vector<int> deck)
{
    queue<int> q;
    vector<int> result(deck.size());
    for (int i = 0; i < deck.size(); i++)
    {
        q.push(i);
    }
    sort(deck.begin(), deck.end());

    // 2 3 5 7 11 13 17

    for (int i = 0; i < deck.size(); i++)
    {
        result[q.front()] = deck[i];
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return result;
}
int main()
{
    deckRevealedIncreasing({17, 13, 11, 2, 3, 5, 7});
    return 0;
}