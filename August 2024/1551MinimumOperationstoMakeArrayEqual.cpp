#include <bits/bits-stdc++.h>
using namespace std;
int minOperations(int n)
{
    int sn = n / 2 * (2 * 1 + (n - 1) * 2);
    int target = sn / n;

    int requiredCost = 0;
    for (int i = 0; i < n; i++)
    {
        int current = 2 * i + 1;

        requiredCost += abs(target - current);
    }

    return requiredCost / 2;
}
int main()
{
    cout << minOperations(6);
    return 0;
}