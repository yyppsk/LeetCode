#include <bits/bits-stdc++.h>
using namespace std;

long long minEndSpace(int n, int x)
{
    vector<short> shifts;
    long long cur = x;
    long long calc = n - 1;

    for (int i = 0; i < 32; i++) // find bit positions in x which are 0
        if (!((1 << i) & x))
            shifts.push_back(i);
    for (int i = 32; i < 64; i++)
        shifts.push_back(i);

    // for(auto x: shifts) cout<<x<<' ';

    for (int i = 0; calc > 0; i++, calc >>= 1)
    {
        cur += (calc & 1) << shifts[i];
    }
    return cur;
}
// TLE After 656 / 765 test cases passed.
long long minEnd_1(int n, int x)
{
    long long number = x;

    while (n > 0)
    {
        if ((number & x) == x)
        {
            n--;
        }
        number++;
    }
    return number - 1;
}

long long minEnd(int n, int x)
{
    long long number = x;
    while (--n)
        number = (number + 1) | x;
    return number;
}
int main()
{
    minEnd(100,
           7193485);
    return 0;
}