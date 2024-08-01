#include <bits/bits-stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{
    int count = 0;

    int k = 32;
    while (k--)
    {
        if ((start & 1) != (goal & 1))
            count++;
        start = start >> 1;
        goal = goal >> 1;
    }

    return count;
}

int main()
{
    cout << minBitFlips(10, 7);
    return 0;
}