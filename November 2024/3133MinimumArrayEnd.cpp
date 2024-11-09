#include <bits/bits-stdc++.h>
using namespace std;

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