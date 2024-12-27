#include <bits/bits-stdc++.h>
using namespace std;
int minCostToMoveChips(vector<int> &position)
{
    int odd = 0, even = 0;
    for (int i = 0; i < position.size(); i++)
    {
        if (position[i] % 2 == 0)
        {
            even += 1;
        }
        else
        {
            odd += 1;
        }
    }

    return min(odd, even) * 1;
}
int main()
{
    return 0;
}