#include <bits/bits-stdc++.h>
using namespace std;

int passThePillow(int n, int time)
{
    int completeRound = time / (n - 1);
    int extra = time % (n - 1);

    if (completeRound % 2 == 0)
    {
        return extra + 1;
    }
    {
        return n - extra;
    }
}
int main()
{
    return 0;
}