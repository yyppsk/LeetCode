#include <bits/bits-stdc++.h>
using namespace std;
int commonFactors(int a, int b)
{
    int commonFact = 0;
    for (int x = 1; x <= min(a, b); x++)
    {
        if (a % x == 0 && b % x == 0)
        {
            commonFact += 1;
        }
    }

    return commonFact;
}
int main()
{
    return 0;
}